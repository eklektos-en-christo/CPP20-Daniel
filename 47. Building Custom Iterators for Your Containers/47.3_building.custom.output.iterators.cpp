//
// Created by Εκλεκτός εν Χριστώ on 8/21/24.
//

/*
 * for custom iterators:
 * container should be a class template(generic)
 * container has to model iterator types
 * container needs to provide begin() and end() members that return those iterators
 * iterators should be modelled as nested class and should provide type aliases which are needed by
 * the standard library
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

    std::cout << box1 << '\n';
    std::cout << box2 << '\n';

    // dereference operator* helps to write data to box2
    std::ranges::copy(box1.begin(), box1.end(), box2.begin());

    std::cout << box1 << '\n';
    std::cout << box2 << '\n';

    return 0;
}