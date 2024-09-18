//
// Created by Εκλεκτός εν Χριστώ on 5/10/24.
//

/*
 * if the defaulted equality doesn't suit the requirements of the program, then we can
 * define the custom equality operator, compiler will generate the != also by seeing our
 * custom equality operator==, implicit conversions will also work, if left operand is
 * another than the implicit type, then it will be flipped or converted by the compiler
 */

#include <iostream>
#include "classes/Point.h"

int main()
{
    Point p1{ 82.1, 82.1 };
    Point p2{ 87.6, 54.3 };

    std::cout << p1 << '\n';
    std::cout << p2 << '\n';

    std::cout << (p1 == p2) << '\n';
    std::cout << (p1 != p2) << '\n';    // compiler generated !=
    std::cout << (82.1 == p1) << '\n';  // works
    std::cout << (p2 != 87.6) << '\n';  // works

    return 0;
}