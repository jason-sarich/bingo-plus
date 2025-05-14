#include <bitset>
#include <vector>
#include "patternfactory.h"

namespace Bingo {

std::map<std::string, std::vector<std::bitset<25>>> PatternFactory::patternlist{};

PatternFactory::PatternFactory()
{
    patternlist["coverall"] = std::vector<std::bitset<25>>
        { { 0b11111'11111'11111'11111'11111} };
    patternlist["two rows"] = std::vector<std::bitset<25>>
        { { 0b11111'11111'00000'00000'00000,
            0b00000'00000'0000'11111'11111} };
    patternlist["any line or corners"] = std::vector<std::bitset<25>>
        { { 0b11111'00000'00000'00000'00000,
            0b00000'11111'00000'00000'00000,
            0b00000'00000'11111'00000'00000,
            0b00000'00000'00000'11111'00000,
            0b00000'00000'00000'00000'11111,
            0b10000'10000'10000'10000'10000,
            0b01000'01000'00000'01000'01000,
            0b00100'00100'00100'00100'00100,
            0b00010'00010'00010'00010'00010,
            0b00001'00001'00001'00001'00001,
            0b10000'01000'00100'00010'00001,
            0b00001'00010'00100'01000'10000,
            0b10001'00000'00000'00000'10001,
            0b00000'01010'00000'01010'00000 } };
    patternlist["two stamps"] = std::vector<std::bitset<25>>
        {  {0b11011'11011'00000'00000'00000,
            0b11000'11000'00000'11000'11000,
            0b11000'11000'00000'00011'00011,
            0b00011'00011'00000'11000'11000,
            0b00011'00011'00000'00011'00011,
            0b00000'00000'00000'11011'11011} };

    patternlist["four stamps"] = std::vector<std::bitset<25>>
        {  {0b11011'11011'00000'11011'11011}};

    patternlist["small square"] = std::vector<std::bitset<25>>
        {  {0b00000'01110'01010'01110'00000}};

    patternlist["x"] = std::vector<std::bitset<25>>
        {  {0b10001'01010'00100'01010'10001}};

    patternlist["pipe"] = std::vector<std::bitset<25>>
        {  {0b00000'01000'11111'00000'00000}};
    patternlist["dog bone"] = std::vector<std::bitset<25>>
        {  {0b00000'10001'01110'10001'00000}};
    patternlist["kite"] = std::vector<std::bitset<25>>
        {  {0b11000'11000'00100'00010'00001}};
    patternlist["airplane"] = std::vector<std::bitset<25>>
        {  {0b00010'10010'11111'10010'00010}};
    patternlist["seven"] = std::vector<std::bitset<25>>
        {  {0b11111'00010'00100'01000'10000}};
    patternlist["sign"] = std::vector<std::bitset<25>>
        {  {0b01110'01110'01110'00100'00100}};




    /*
    patternlist = std::map<std::string, std::vector<std::bitset<25>>> {
            {"coverall", std::vector<std::bitset<25>> {0b1'1111'1111'1111'1111'1111'1111} },
    };*/

}

} // namespace Bingo
