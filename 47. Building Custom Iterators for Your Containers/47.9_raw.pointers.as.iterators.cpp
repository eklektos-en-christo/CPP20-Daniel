//
// Created by Εκλεκτός εν Χριστώ on 9/1/24.
//

/*
 * instead of returning iterators, we can return pointers. they act the same like pointers
 */

#include <iostream>
#include "raw_pointers/boxcontainer.h"
#include <ranges>
#include <algorithm>

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

    // pointers as iterators
    for (auto i : box1)
        std::cout << i << ' ';
    std::cout << '\n';

    // pointers as iterators
    for (auto it{ box1.begin() }; it != box1.end(); ++it)
        std::cout << *it << ' ';

    const auto box1_copy{ box1 };

    std::ranges::sort(box1);

    // const collection can't be sorted
    /*std::ranges::sort(box1_copy);*/

    return 0;
}