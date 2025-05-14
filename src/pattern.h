#ifndef PATTERN_H
#define PATTERN_H

#include <bitset>
#include <map>
#include <memory>
#include <iostream>
#include <vector>

#include "bingo.h"

namespace Bingo {

class Pattern
/*
  Each pattern is a vector of bitsets that represent the possible
  winning patterns

  0 | 1 | 2 | 3 | 4
  5 | 6 | 7 | 8 | 9
 10 |11 |12 |13 |14
 15 |16 |17 |18 |19
 20 |21 |22 |23 |24

 Note that 12 is the free space and we are including it here
*/
{
private:
    const std::vector<std::bitset<25>> m_patterns;
public:

    Pattern()=delete;

    // Initialize with a vector of patterns
    Pattern(const std::vector<std::bitset<25>>& patterns)
        : m_patterns{patterns} {}

    std::vector<std::vector<size_t>> combinations(const int k) const;

    // TODO: Initialize with one pattern
    /*    Pattern(std::bitset<25>& pattern)
      : m_patterns{new std::vector<Pattern> {pattern}} {}*/

    const std::vector<std::bitset<25>>& get_patterns() const
    {
        return m_patterns;
    }

    bool check_for_bingo(const std::bitset<25> card);
    friend std::ostream& operator<<(std::ostream& out, const Pattern& ps);


};

} // namespace Bingo

#endif // PATTERN_H
