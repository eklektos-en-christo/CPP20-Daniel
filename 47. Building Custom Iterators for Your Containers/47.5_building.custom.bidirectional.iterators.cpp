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

    std::cout << box1 << '\n';

    // operator-- helps in moving backwards
    std::ranges::reverse(box1);

    std::cout << box1 << '\n';

    for (auto it{ box1.end() }; it != box1.begin();)
        std::cout << *(--it) << '\n';

    return 0;
}