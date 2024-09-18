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
    std::vector<int> vector{ 2, 1, 3, 4, 9, 5, 8, 7 };
    std::cout << vector << '\n';

    if (std::ranges::find(vector, 5) != vector.end())
        std::cout << "vector contains 5" << '\n';
    else
        std::cout << "vector does not contain 5" << '\n';

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

    if (std::ranges::find(box1, 3) != box1.end())
        std::cout << "box1 contains 3" << '\n';
    else
        std::cout << "box1 doesn't contain 3" << '\n';

    return 0;
}