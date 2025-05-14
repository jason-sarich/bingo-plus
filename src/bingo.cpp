#include <vector>
#include <map>
#include <bitset>
#include "bingo.h"


namespace Bingo {

Globals::Globals()
{
}
const std::vector<char> Globals::bingo_letters = std::vector<char>{'B','I','N','G','O'};
const std::vector<int> Globals::allB {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
const std::vector<int> Globals::allI {16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
const std::vector<int> Globals::allN {31,32,33,34,35,36,37,38,39,40,41,42,43,44,45};
const std::vector<int> Globals::allG {46,47,48,49,50,51,52,53,54,55,56,57,58,59,60};
const std::vector<int> Globals::allO {61,62,63,64,65,66,67,68,69,70,71,72,73,74,75};

std::random_device Globals::rd {};
std::mt19937 Globals::random_generator{Globals::rd()};



int Globals::getcol(char letter)
{
    switch (letter) {
    case 'B':
        return 0;
    case 'I':
        return 1;
    case 'N':
        return 2;
    case 'G':
        return 3;
    case 'O':
        return 4;
    default:

        return -1;
    }

}
}
