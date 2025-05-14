#include <vector>
#include <map>
#include <bitset>
#include <algorithm>
#include "bingo.h"
#include "pattern.h"
#include "card.h"
namespace Bingo {

Card::Card()
    : B {Globals::allB}, I {Globals::allI}, N {Globals::allN}, G {Globals::allG}, O {Globals::allO}, m_bingo_letter_map{}
    {
        m_bingo_letter_map['B'] = B;
        m_bingo_letter_map['I'] = I;
        m_bingo_letter_map['N'] = N;
        m_bingo_letter_map['G'] = G;
        m_bingo_letter_map['O'] = O;
        std::shuffle(B.begin(), B.end(), Globals::random_generator);
        std::shuffle(I.begin(), I.end(), Globals::random_generator);
        std::shuffle(N.begin(), N.end(), Globals::random_generator);
        std::shuffle(G.begin(), G.end(), Globals::random_generator);
        std::shuffle(O.begin(), O.end(), Globals::random_generator);

        B.resize(5);
        I.resize(5);
        N.resize(4);
        G.resize(5);
        O.resize(5);
        m_marks.reset();
        m_marks[12] = true;
    }

    void Card::print() const
    {
        std::cout << "B  I  N  G  O\n" ;
        for (size_t i=0; i<5; i++) {
            std::cout << B[i] << " " << I[i] << " ";
            if (i==2) std::cout << " F" << " ";
            else if (i<2) std::cout << N[i] << " ";
            else std::cout << N[i-1] << " ";
            std::cout << G[i] << " " << O[i] << " " << std::endl;
        }
    }
    void Card::unmark(int number)
    {
        int sq = m_find_on_card(number);
        if (sq >= 0)
            m_marks[sq] = false;
    }
    void Card::mark(int number)
    {
        int sq = m_find_on_card(number);
        if (sq >= 0)
            m_marks[sq] = true;

    }
    int Card::m_find_on_card(int number) const
    {
        const std::vector<int> *colPtr;
        bool isN {false};
        int row=-1,col;
        if (number<=15) {
            col=0;
            colPtr=&B;
        } else if (number<=30) {
            col=1;
            colPtr=&I;
        } else if (number<=45) {
            col=2;
            colPtr=&N;
            isN = true;
        } else if (number<=60) {
            col=3;
            colPtr=&G;
        } else {
            col=4;
            colPtr=&O;
        }
        for (size_t i=0; i<colPtr->size(); ++i) {
            if (colPtr->at(i) == number) {
                row = i;
                if (isN && i>=2) {
                    row++;
                }
                break;
            }
        }
        if (row>=0)
            return row*5+col;
        else
            return -1;
    }


    bool Card::is_marked(char bingo_letter, int row) const
    {
        if (bingo_letter=='N' and row == 2) {
            return true;
        }
        int col = Globals::getcol(bingo_letter);
        int index = row*5+col;

        return m_marks[index];
    }

    bool Card::is_marked(int index) const
    {
        return m_marks[index];
    }

    bool Card::has_bingo(Pattern pattern) const
    {
        return (pattern.check_for_bingo(m_marks));
    }
    void Card::reset()
    {
        m_marks.reset();
        m_marks[12]=true;

    }

} // namespace Bingo
