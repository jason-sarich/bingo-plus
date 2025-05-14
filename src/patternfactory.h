#ifndef PATTERNFACTORY_H
#define PATTERNFACTORY_H
#include <memory>
#include <vector>
#include <bitset>
#include <map>
#include "pattern.h"

namespace Bingo {

class PatternFactory
{
private:
    static std::map<std::string, std::vector<std::bitset<25>>> patternlist;

public:
    PatternFactory();

    // Create pattern by name
    std::unique_ptr<Pattern> createPattern(const std::string name)
    {

        if (patternlist.count(name) >= 1) { //Note requires C++20
            return createPattern(patternlist.at(name));
        } else {
            return nullptr;
        }
    }

    // Create pattern by bitsets
    std::unique_ptr<Pattern> createPattern(const std::vector<std::bitset<25>>& plist)
    {
        return std::make_unique<Pattern>(plist);
    }

};

} // namespace Bingo

#endif // PATTERNFACTORY_H
