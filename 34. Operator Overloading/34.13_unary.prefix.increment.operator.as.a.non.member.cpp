//
// Created by Εκλεκτός εν Χριστώ on 5/7/24.
//

/*
 *
 */

#include <iostream>
#include "classes/Point.h"

int main()
{
    Point p1{ 2.1, 6.1 };
    ++p1;

    std::cout << p1 << '\n';

    return 0;
}