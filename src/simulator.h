#ifndef SIMULATOR_H
#define SIMULATOR_H
#include <string>
#include <vector>
#include <memory>
#include "caller.h"
#include "card.h"
#include "pattern.h"

namespace Bingo {

class Simulator
{
private:
    int m_nsims {0};
    std::string m_pattern_name {};
    std::unique_ptr<Pattern> m_patternPtr{};
    std::vector<int> m_startup;

    int m_N_bingo_already {0};
    int m_N_bingo_B {0};
    int m_N_bingo_I {0};
    int m_N_bingo_N {0};
    int m_N_bingo_G {0};
    int m_N_bingo_O {0};

    bool m_pick_and_test(const char c, Caller& caller, Card &card) const;
public:
    Simulator()=delete;
    Simulator(std::string pattern_name, const std::vector<int> &startup, int nsims);
    void run();
    void print_results();


};

} // namespace Bingo

#endif // SIMULATOR_H
