#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <bitset>
#include <algorithm>
#include <random>
#include "bingo.h"
#include "pattern.h"

namespace Bingo {

class Card
    // Bingo card stuff
    //    mark
    //    unmark
    //    check if winner
    //    create random
    //    get display information (numbers and marks)
    //    crude output of card
{
private:
    std::bitset<25> m_marks {};
    std::vector<int> B,I,N,G,O; // copies
    std::map<char, std::vector<int>> m_bingo_letter_map;
    int m_find_on_card(int) const;
public:
    Card();
    void mark(int number);
    void unmark(int number);
    bool is_marked(char bingo_letter, int row) const;
    bool is_marked(int index) const;
    void print() const;
    bool has_bingo(Pattern pattern) const;
    void reset();
};

} // namespace Bingo

#endif // CARD_H
