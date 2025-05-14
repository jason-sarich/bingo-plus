#ifndef COLUMN_H
#define COLUMN_H
#include <bitset>
#include <map>
#include <memory>

namespace Bingo {

class Column
{
private:
    char k;
    const char m_letter {}; // 'B','I','N','G','O'
    const std::bitset<25> m_mask {};
    int m_num_called;


public:
    static const std::map<const char, std::bitset<25>> m_colmap;

    static std::unique_ptr<Column> create_column(const char c);
    Column()=delete;
    Column(const char c);
    char get_letter() const;
    const std::bitset<25>& get_mask() const;
    int count_needed(const std::bitset<25>& pattern_map) const;
    int get_num_called() const;
    void add_letter();
    void pop_letter();
};

} // namespace Bingo

#endif // COLUMN_H
