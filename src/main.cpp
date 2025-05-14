#include <iostream>
#include <memory>
#include "bingo.h"
#include "pattern.h"
#include "patternfactory.h"
#include "card.h"
#include "caller.h"
#include "odds.h"
#include "simulator.h"

int main()
{
    int n;
    // Generate and print card, mark first square, print if it's marked
    Bingo::Card card {};
    card.print();

    // Generate coverall pattern, print it out
    Bingo::PatternFactory factory{};
    std::unique_ptr<Bingo::Pattern> pPtr {factory.createPattern("two rows")};
    Bingo::Pattern pattern = *(pPtr.get());
    std::cout << pattern << std::endl;

    std::vector<int> startup {12,12,12,12,12};
    Bingo::Simulator simulator{"two rows", startup, 1000};
    simulator.run();
    simulator.print_results();

    return 0;
}
