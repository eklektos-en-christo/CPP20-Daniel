//
// Created by Εκλεκτός εν Χριστώ on 5/8/24.
//

/*
 * we can overload them as member funcs and not member funcs
 */

#include <iostream>
#include "classes/Point.h"

int main()
{
    Point p1{ 2.7, 1.3 };
    Point p2{ 8.2, 0.7 };

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