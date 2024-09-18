//
// Created by Εκλεκτός εν Χριστώ on 5/1/24.
//

/*
 * overloading the compound operators and using previous defined operators with new operators
 */

#include <iostream>
#include "classes/Point.h"

int main()
{
    Point p1{ 23.8, 6.7 };
    Point p2{ 6.1, 8.8 };

    p1 += p2;

    std::cout << p1 << '\n';

    p1 -= p2;

    std::cout << p1 << '\n';

    std::cout << p1 + p2 + p1 << '\n';
    std::cout << p1 - p2 - p2 << '\n';

    return 0;
}