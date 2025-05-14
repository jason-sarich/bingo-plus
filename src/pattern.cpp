#include <bitset>
#include <map>
#include <iterator>
#include <algorithm>
#include <vector>

#include "pattern.h"


namespace Bingo {



bool Pattern::check_for_bingo(const std::bitset<25> card_marks)
{
    for (auto p : m_patterns)
    {
        if ((card_marks & p) == p) return true;
    }
    return false;
}

std::vector<std::vector<size_t>> Pattern::combinations(const int k) const
{
    size_t n = m_patterns.size();
    if (k>n) return std::vector<std::vector<size_t>>{};
    std::vector<bool> bits {};
    std::vector<std::vector<size_t>> retval;
    std::vector<size_t> curvec;
    for (int i=0;i<k;i++) bits.push_back(true);
    for (int i=k;i<n;i++) bits.push_back(false);

    do {
        curvec = std::vector<size_t>{};
        for (int i = 0; i < n; ++i) // [0..N-1] integers
        {
            if (bits[i]) curvec.push_back(i);
        }
        retval.push_back(curvec);

    } while (std::prev_permutation(bits.begin(), bits.end()));
    return retval;
}

std::ostream& operator<<(std::ostream& out, const Bingo::Pattern& P)
{
    for (const auto p : P.get_patterns()) {
        out << "BINGO\n";
        out << "-----\n";
        for (size_t row=0; row<5; row++) {
            for (size_t col=0; col<5; col++) {
                out << (p[row*5+col]) ? "O" : "-";
            }
            out << "\n";
        }
    }
    return out;
}


} // namespace Bingo
