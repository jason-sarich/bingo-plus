#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>
#include <vector>
#include "caller.h"
#include "simulator.h"
#include "pattern.h"
#include "patternfactory.h"
#include "card.h"
#include "odds.h"

namespace Bingo {

Simulator::Simulator(std::string pattern_name, const std::vector<int>&  start, int nsims=1000)
    : m_pattern_name {pattern_name}, m_startup{start}, m_nsims {nsims}
{
    Bingo::PatternFactory factory{};
    m_patternPtr = factory.createPattern(m_pattern_name);
}

bool Simulator::m_pick_and_test(const char letter, Caller& caller, Card& card) const
{
    int low{}, high{};
    switch (letter) {
    case 'B':
        low=1;high=15;break;
    case 'I':
        low=16;high=30;break;
    case 'N':
        low=31;high=45;break;
    case 'G':
        low=46;high=60;break;
    case 'O':
        low=61;high=75;break;
    default:
        throw std::string("Unexpected letter");
    }
    std::vector<int> sample_space;
    for (int i=low; i<=high; i++) {
        if (!caller.is_called(i)) {
            sample_space.push_back(i);
        }
    }
    std::shuffle(sample_space.begin(), sample_space.end(),Globals::random_generator);
    int n = sample_space.at(0);
    card.mark(n);
    bool retval = card.has_bingo(*m_patternPtr);
    card.unmark(n);
    return retval;
}



void Simulator::run()
{
    Caller caller {};
    Card card {}; // Use the same card every iteration??
    m_N_bingo_already=0;
    m_N_bingo_B=0;
    m_N_bingo_I=0;
    m_N_bingo_N=0;
    m_N_bingo_G=0;
    m_N_bingo_O=0;
    std::vector<int> space{};

    for (int i=0; i<m_nsims; ++i) {
        caller.reset(m_startup);
        card.reset();
        int nb{0}, ni{0}, nn{0}, ng{0}, no{0};
        for (size_t letter=0;letter<5;letter++) {
            for (int j=0; j<m_startup[letter]; j++) {
                int b = caller.call_next();
                card.mark(b);
            }
        }
        if (card.has_bingo(*m_patternPtr)) {
            m_N_bingo_already++;
        } else {
            if (m_pick_and_test('B',caller,card)) m_N_bingo_B++;
            if (m_pick_and_test('I',caller,card)) m_N_bingo_I++;
            if (m_pick_and_test('N',caller,card)) m_N_bingo_N++;
            if (m_pick_and_test('G',caller,card)) m_N_bingo_G++;
            if (m_pick_and_test('O',caller,card)) m_N_bingo_O++;

        }
    }
}

void Simulator::print_results()
{
    int n_trials = m_nsims - m_N_bingo_already;
    int count=0;
    double pbingo (0.0);
    double predict_b {0.0}, predict_i{0.0}, predict_n{0.0}, predict_g{0.0},predict_o{0.0};

    Odds odds{};
    char lmap[5] {'B','I','N','G','O'};
    for (size_t i=0;i<m_startup.size();i++)
    {
        for (int j=0;j<m_startup[i];j++)
            odds.push_letter(lmap[i]);
    }
    pbingo = odds.calc_prob_bingo_current(*m_patternPtr);

    std::cout << "startup = [";
    for (size_t i=0;i<m_startup.size(); i++)
    {
        count += m_startup[i];
        std::cout << m_startup[i] << (i<4 ? ", " : "]\n");
    }
    std::cout << "Bingos after " << count << ": " << m_N_bingo_already << "/";
    std::cout << m_nsims << " " << m_N_bingo_already*100.0/m_nsims << "% -- predicted ";
    std::cout << pbingo*100.0 << std::endl;

    predict_b = odds.calc_prob_bingo_next('B',*m_patternPtr);
    predict_i = odds.calc_prob_bingo_next('I',*m_patternPtr);
    predict_n = odds.calc_prob_bingo_next('N',*m_patternPtr);
    predict_g = odds.calc_prob_bingo_next('G',*m_patternPtr);
    predict_o = odds.calc_prob_bingo_next('O',*m_patternPtr);



    std::cout << "Winner on B: " << m_N_bingo_B << " " << 1.0*m_N_bingo_B/n_trials << "| predicted: " << predict_b << "\n";
    std::cout << "Winner on I: " << m_N_bingo_I << " " << 1.0*m_N_bingo_I/n_trials << "| predicted: " << predict_i << "\n";
    std::cout << "Winner on N: " << m_N_bingo_N << " " << 1.0*m_N_bingo_N/n_trials << "| predicted: " << predict_n << "\n";
    std::cout << "Winner on G: " << m_N_bingo_G << " " << 1.0*m_N_bingo_G/n_trials << "| predicted: " << predict_g << "\n";
    std::cout << "Winner on O: " << m_N_bingo_O << " " << 1.0*m_N_bingo_O/n_trials << "| predicted: " << predict_o << "\n";

}
} // namespace Bingo
