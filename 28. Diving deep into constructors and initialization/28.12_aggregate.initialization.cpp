//
// Created by Εκλεκτός εν Χριστώ on 4/2/24.
//

/*
 * aggregate initialization - a unified way to initialize the aggregates
 */

#include <iostream>

struct Point
{
    double x;
    double y;
};

int main()
{
    // aggregate initialization with struct/class
    Point p1{ 2.8, 9.2 };

    // aggregate initialization with arrays
    int scores[]{ 2, 3, 9, 5, 7 };

    return 0;
}