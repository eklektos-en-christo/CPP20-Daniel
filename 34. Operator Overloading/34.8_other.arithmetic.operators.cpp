//
// Created by Εκλεκτός εν Χριστώ on 5/1/24.
//

/*
 * just because you can overload an operator doesn't mean you should, it should make sense
 */

#include <iostream>
#include "classes/Point.h"

int main()
{
    Point p1{ 0.1, 0.8 };
    Point p2{ 0.119, 2.231 };

    std::cout << p2 + p1 << '\n';
    std::cout << p2 - p1 << '\n';

    return 0;
}