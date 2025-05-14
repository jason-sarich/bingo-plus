#define __STDCPP_WANT_MATH_SPEC_FUNCS__ 1
#include <algorithm>
#include <bitset>
#include <cmath>
#include <map>
#include <memory>
#include "bingo.h"
#include "column.h"
#include "odds.h"
#include "pattern.h"

namespace Bingo {

Odds::Odds()
{
    for (auto c : Bingo::Globals::bingo_letters) {
        m_columns[c] = Column::create_column(c);
    }
}
double Odds::nCk(int n, int k) const
{
    return 1/((n+1)*std::beta(n-k+1,k+1));
}



void  Odds::push_letter(const char c) {
    m_columns[c]->add_letter();
}
void Odds::pop_letter(const char c)
{
    m_columns[c]->pop_letter();
}

double Odds::calc_prob_k_winners(double prob, int k, int num_cards) const
{
    if (k>num_cards)
        return 0.0;
    else if (k==num_cards)
        return prob;
    else {
        return nCk(num_cards,k) * pow(prob,k) * pow(1.0-prob, num_cards-k);
    }
}
double Odds::calc_prob_bingo_current_one_pattern(const std::bitset<25> bitmap) const
{
    int needed, ncalled;
    double prob = 1.0;
    for (const auto k : Bingo::Globals::bingo_letters) {
        needed = m_columns.at(k)->count_needed(bitmap);
        ncalled = m_columns.at(k)->get_num_called();
        if (needed > ncalled)
            return 0.0;
        if (needed > 0) {
            prob *= nCk(15-needed,ncalled-needed)/nCk(15,ncalled);
        }
    }
    //std::cout << "prob=" << prob << "\n";
    return prob;
}
double Odds::calc_prob_bingo_current (const Pattern pattern) const
{
    double prob=0, temp_prob;
    const double tol=1.0e-7;
    int sign, level;
    std::vector<std::vector<size_t>> combinations{};
    std::bitset<25> p;
    const std::vector<std::bitset<25>> &bmvec = pattern.get_patterns();
    for (auto &bm : bmvec ) {
        prob += calc_prob_bingo_current_one_pattern(bm);
    }

    sign =-1; level=1; temp_prob=1.0;
    while (temp_prob > tol && level < bmvec.size())
    {
        temp_prob=0.0;
        combinations = pattern.combinations(level+1);
        for (auto comb : combinations) {
            p = bmvec.at(comb[0]);
            for (size_t i=1; i<comb.size(); i++) {
                p |= bmvec.at(comb[i]);
            }
            temp_prob += calc_prob_bingo_current_one_pattern(p);
        }
        prob = prob + sign * temp_prob;
        sign *= -1;
        level += 1;
    }

    return prob;
}

double Odds::calc_prob_bingo_next (const char letter, const Pattern pattern)
{
    double p_before = calc_prob_bingo_current(pattern);
    push_letter(letter);
    double p_now = calc_prob_bingo_current(pattern);
    pop_letter(letter);
    return (p_now-p_before)/(1.0-p_before);
}
} // namespace Bingo
