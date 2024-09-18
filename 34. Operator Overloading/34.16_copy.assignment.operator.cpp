//
// Created by Εκλεκτός εν Χριστώ on 5/8/24.
//

/*
 * compiler generates the copy assignment operator is there is none provided, it performs the
 * shallow copy by default
 *
 * copy assignment operator can only be implemented as a member function, assignment works only
 * with already created objects and not new objects that are being created
 *
 * self assignment check is necessary both in copy assignment and copy constructor
 */

#include <iostream>
#include "classes/Point.h"

int main()
{
    Point p1{ 2, 8, 101 };
    Point p2{ 1, 7, 101 };

    // assignment - calls operator=, memberwise deep copy, no crashes
    p2 = p1;

    std::cout << p1 << '\n';
    std::cout << p2 << '\n';

    // = here doesn't mean that assignment operator is called,
    // this calls the copy constructor because a new object is being created
    Point p3 = p2;
    std::cout << p3 << '\n';

    // chained assignments - possible, in each assignment the Point object is returned
    /*p1 = p2 = p3;*/
    // equivalent of previous statement
//    p1.operator=(p2.operator=(Point{0,0,0}));

    // not right, operator is called on p1, both times, anonymous Point overwrites the data of p2
    // which was copied to p1, p2 remains unchanged
    p1.operator=(p2).operator=(Point{0,0,0});

    std::cout << p1 << '\n';
    std::cout << p2 << '\n';

    return 0;
}