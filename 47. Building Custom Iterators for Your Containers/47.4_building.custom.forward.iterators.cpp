//
// Created by Εκλεκτός εν Χριστώ on 8/29/24.
//

/*
 *
 */

#include <iostream>
#include <algorithm>
#include "classes/boxcontainer.h"
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vec)
{
    for (auto i : vec)
        out << i << ' ';
    return out;
}

int main()
{
    BoxContainer<int> box1;
    box1.add(2);
    box1.add(1);
    box1.add(3);
    box1.add(4);
    box1.add(9);
    box1.add(5);
    box1.add(8);
    box1.add(7);

    BoxContainer<int> box2;

    for (std::size_t i{0}; i < box1.size(); ++i)
        box2.add(0);

    std::ranges::copy(box1.begin(), box1.end(), box2.begin());

    std::cout << box1 << '\n';

    // operator++ helps to move forward in container and change the 9 with 91
    std::ranges::replace(box1.begin(), box1.end(), 9, 91);

    std::cout << box1 << '\n';

    return 0;
}