#include <map>
#include <bitset>
#include <memory>
#include "column.h"

namespace Bingo {


std::unique_ptr<Column> Column::create_column(const char c)
{

    return std::make_unique<Column>(c);
}
const std::map<const char, std::bitset<25>> Column::m_colmap = std::map<const char, std::bitset<25>> {
    {'B',std::bitset<25>{"1000010000100001000010000"}},
    {'I',std::bitset<25>{"0100001000010000100001000"}},
    {'N',std::bitset<25>{"0010000100001000010000100"}},
    {'G',std::bitset<25>{"0001000010000100001000010"}},
    {'O',std::bitset<25>{"0000100001000010000100001"}}
};

Column::Column(const char c)
    : m_letter{c}, m_num_called{0}, m_mask{m_colmap.at(c)}
{

}

char Column::get_letter() const
{
    return m_letter;
}


const std::bitset<25>& Column::get_mask() const
{
    return m_mask;
}

int Column::count_needed(const std::bitset<25>& pattern_map) const
{
    if (m_letter == 'N' && pattern_map[12])
        return std::max(static_cast<int>((pattern_map & m_mask).count())-1,0);
    else
        return (pattern_map & m_mask).count();
}

int Column::get_num_called() const
{
    return m_num_called;
}
void Column::add_letter()
{
    m_num_called++;
}

void Column::pop_letter()
{
    m_num_called--;
}

} // namespace Bingo
