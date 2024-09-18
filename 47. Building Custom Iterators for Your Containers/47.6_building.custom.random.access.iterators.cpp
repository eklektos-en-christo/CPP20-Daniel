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

    // random access iterators help the sort to sort elements
    std::ranges::sort(box1.begin(), box1.end());

    std::cout << box1 << '\n';

    return 0;
}