#ifndef ODDS_H
#define ODDS_H

#include <bitset>
#include <map>
#include "column.h"
#include "pattern.h"


namespace Bingo {

class Odds
{
private:
    std::map<const char, std::unique_ptr<Column>> m_columns;


public:
    Odds();
    double nCk(int n, int k) const;
    void push_letter(const char c);
    void pop_letter(const char c);

    double calc_prob_k_winners(double prob, int k, int num_cards) const;
    double calc_prob_bingo_current (const Pattern pattern) const;
    double calc_prob_bingo_next (const char c, const Pattern pattern);  //not const because push and pop

private:
    double calc_prob_bingo_current_one_pattern(const std::bitset<25> bitmap) const;
};

} // namespace Bingo

#endif // ODDS_H
