//
// Created by Εκλεκτός εν Χριστώ on 9/1/24.
//

/*
 * constant iterators : non const iterators won't work with const types, they might be used to modify
 * the const container
 */

#include <iostream>
#include "classes/boxcontainer.h"
#include <ranges>
#include <algorithm>

template <typename T>
void print(const BoxContainer<T>& box)
{
    for (auto i : box)
        std::cout << *i << ' ';
    std::cout << '\n';
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

    const BoxContainer<int> box1_copy{ box1 };

    // const iterator are used to print the box1
    for (auto item : box1_copy)
        std::cout << item << ' ';

    return 0;
}