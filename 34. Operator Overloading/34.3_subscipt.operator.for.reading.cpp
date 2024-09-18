//
// Created by Εκλεκτός εν Χριστώ on 4/27/24.
//

/*
 * subscipt operator[] - must be setup as a member function
 */

#include <iostream>
#include "classes/Point.h"

int main()
{
    Point p1{ 2.1, 3.6 };

    std::cout << p1[0] << '\n';
    std::cout << p1[1] << '\n';
    std::cout << p1.operator[](1) << '\n';

    return 0;
}