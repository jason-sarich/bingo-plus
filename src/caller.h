#ifndef CALLER_H
#define CALLER_H

#include <vector>
#include <array>

namespace Bingo {

class Caller
{
private:
    std::vector<int> m_balls {};
    size_t m_index {0};
    std::array<int,76> m_called {};
public:
    Caller();
    // constructor with know set of starting balls (For simulations)
    Caller(std::vector<int> start);

    // reshuffle and restart
    void reset();
    void reset(std::vector<int> start);

    int call_next();
    void undo_last();

    // returns if this number has already been called
    bool is_called(int n) const;

    void print() const;



    // pick N numbers from each column, used to setup caller for sims
    void pick_from_and_add(std::vector<int> temp, int n);
};

} // namespace Bingo

#endif // CALLER_H
