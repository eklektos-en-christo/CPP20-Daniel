//
// Created by Εκλεκτός εν Χριστώ on 5/8/24.
//

/*
 *
 */

#include <iostream>
#include "classes/Point.h"
#include "classes/Car.h"

int main()
{
    Point p1{ 23, 48, 3243 };
    Car c1{ "Toyota", 250 };

    // copying another type to Point - operator= with Car parameter called
    p1 = c1;

    std::cout << p1 << '\n';

    return 0;
}