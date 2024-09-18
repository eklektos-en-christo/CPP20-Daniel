//
// Created by Εκλεκτός εν Χριστώ on 5/12/24.
//

/*
 * compiler doesn't generate == when we implement our own non defaulted custom <=> operator,
 * it generates 4 logical operators, != is generates using ==
 * implicit conversions work even when <=> is a member and not non member
 */

#include <iostream>
#include "classes/Point.h"

int main()
{
    Point p1{ 22.8, 7.6 };
    Point p2{ 31.9, 2.5 };

    // custom <=> working
    std::cout << (p1 < p2) << '\n';
    std::cout << (p1 <= p2) << '\n';
    std::cout << (p1 > p2) << '\n';
    std::cout << (p1 >= p2) << '\n';
    std::cout << (p1 == p2) << '\n';
    std::cout << (p1 != p2) << '\n';

    // implicit conversions work - rewrite rules
    std::cout << (2 != p2) << '\n';
    std::cout << (p1 == 9) << '\n';

    return 0;
}