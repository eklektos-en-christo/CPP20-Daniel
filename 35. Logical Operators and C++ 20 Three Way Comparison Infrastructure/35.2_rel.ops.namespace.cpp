//
// Created by Εκλεκτός εν Χριστώ on 5/9/24.
//

/*
 * std::rel_ops - a way to generate all other logical operator, we only need to specify
 * < and == operator, compiler does the rest, lives in <utility>, deprecated in C++20
 */

#include <iostream>
#include "classes/Point.h"
#include <utility>          // for rel_ops

int main()
{
    Point p1{ 21.7, 87.6 };
    Point p2{ 89.2, 27.3 };

    // can be included in the Point.h
    // compiler generates 4 more operators for Point
    using namespace std::rel_ops;

    std::cout << std::boolalpha;
    std::cout << (p1 < p2) << '\n';
    std::cout << (p1 > p2) << '\n';
    std::cout << (p1 <= p2) << '\n';
    std::cout << (p1 >= p2) << '\n';
    std::cout << (p1 == p2) << '\n';
    std::cout << (p1 != p2) << '\n';

    std::cout << p1 << '\n';
    std::cout << p2 << '\n';

    return 0;
}