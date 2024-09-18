//
// Created by Εκλεκτός εν Χριστώ on 4/27/24.
//

/*
 * non member - free standing global function, it can't access the private members of the class,
 * so it can be declared as a friend of the class, it doesn't have access to the this pointer of the
 * object
 */

#include "classes/Point.h"
#include <iostream>

int main()
{
    Point p1{ 1, 1 };
    Point p2{ 2, 2 };

    auto p3{ operator+(p1, p2) };

    auto p4{ p2 + p3 };

    p3.print_info();
    p4.print_info();

    return 0;
}