#ifndef BINGO_H
#define BINGO_H
#include<vector>
#include<map>
#include<bitset>
#include<random>



/* TODO
 * finish pattern map
 * fun with inheritance
 * card GUI
 * odds GUI
 *   . total numbers called
 *   . plot of balls needed to bingo
 *   . animations?
 */

namespace Bingo {
class Globals {
public:
    Globals();
    static const std::vector<char> bingo_letters;
    static const std::vector<int> allB;
    static const std::vector<int> allI;
    static const std::vector<int> allN;
    static const std::vector<int> allG;
    static const std::vector<int> allO;

    static std::random_device rd;
    static std::mt19937 random_generator;



    static int getcol(char letter);
};
}


#endif // BINGO_H
