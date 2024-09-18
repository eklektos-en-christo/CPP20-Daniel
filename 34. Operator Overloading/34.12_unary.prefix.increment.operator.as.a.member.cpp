//
// Created by Εκλεκτός εν Χριστώ on 5/7/24.
//

/*
 * unary operators - only take single operand
 *
 * we can return void or anything from unary overloaded operators
 */

#include <iostream>
#include "classes/Point.h"

int main()
{
    Point p1{ 2.1, -6.8 };
    std::cout << p1 << '\n';

    ++p1;

    std::cout << p1 << '\n';

    for (std::size_t i{0}; i < 20; ++i)
    {
        ++p1;
        std::cout << p1 << '\n';
    }

    return 0;
}