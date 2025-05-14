#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
#include "bingo.h"
#include "caller.h"

namespace Bingo {

    Caller::Caller()
    : m_balls{}, m_called{}
    {
        for (size_t i=1;i<=75;++i) {
            m_balls.push_back(i);
            m_called[i]=0;
        }
        std::shuffle(m_balls.begin(), m_balls.end(),Globals::random_generator);
        m_index=0;
    }

    Caller::Caller(std::vector<int> start)
        : m_balls{}, m_called{}
    {
        std::vector<int> space {};
        for (size_t i=1;i<=75;++i) {
            space.push_back(i);
            m_called[i]=0;
        }

        pick_from_and_add(Globals::allB, start[0]);
        pick_from_and_add(Globals::allI, start[1]);
        pick_from_and_add(Globals::allN, start[2]);
        pick_from_and_add(Globals::allG, start[3]);
        pick_from_and_add(Globals::allO, start[4]);

        //Add remaining balls
        for (auto n : space) {
            if (!is_called(n)) {
                m_balls.push_back(n);
            }
        }
        //Shuffle remaining balls
        std::shuffle(m_balls.begin()+m_index, m_balls.end(),Globals::random_generator);

    }

    bool Caller::is_called(int num) const
    {
        return (m_called[num]);
    }

    int Caller::call_next()
    {
        if (m_index == 75) {
            throw (std::string{"Caller out of balls"});
        }
        int ball = m_balls[m_index++];
        m_called[ball]=1;
        return ball;
    }
    void Caller::undo_last()
    {
        if (m_index > 0) m_called[--m_index]=0;
    }


    void Caller::reset()
    {
        std::shuffle(m_balls.begin(), m_balls.end(), Globals::random_generator);
        m_index = 0;
        for (size_t i=1; i<=75; ++i) {
            m_called[i]=0;
        }
    }
    void Caller::reset(std::vector<int> start)
    {

        m_balls.clear();
        for (size_t i=1; i<=75; ++i) {
            m_called[i]=0;
        }
        m_index=0;
        pick_from_and_add(Globals::allB, start[0]);
        pick_from_and_add(Globals::allI, start[1]);
        pick_from_and_add(Globals::allN, start[2]);
        pick_from_and_add(Globals::allG, start[3]);
        pick_from_and_add(Globals::allO, start[4]);

        //Add remaining balls
        for (size_t i=1;i<=75;i++) {
            if (!is_called(i)) {
                m_balls.push_back(i);
            }
        }
        //Shuffle remaining balls
        std::shuffle(m_balls.begin()+start[0]+start[1]+start[2]+start[3]+start[4], m_balls.end(), Globals::random_generator);
        for (size_t i=1; i<=75; ++i) {
            m_called[i]=0;
        }



    }


    void Caller::pick_from_and_add(std::vector<int> temp, int n)
    {
        std::random_shuffle(temp.begin(), temp.end());
        temp.resize(n);
        for (auto b : temp) {
            m_balls.push_back(b);
            m_called[b] = 1;
        }
    }

    void Caller::print() const
    {
        int count {0};
        std::cout << "index = " << m_index << "\n";
        std::cout << "Already called: \n";
        for (count=0; count<m_index; ++count) {
            std::cout << m_balls.at(count) << " ";
        }
        std::cout << "\nComing next: \n";
        for (count=m_index; count<m_balls.size(); ++count) {
            std::cout << m_balls.at(count) << " ";
        }
        std::cout << std::endl;
    }
} // namespace Bingo
