//
// Created by Εκλεκτός εν Χριστώ on 5/8/24.
//

/*
 * type conversion methods:
 *
 * - we can implement a type conversion operator
 * - we can make a constructor taking the type which is to be converted
 * - we can implement a copy assignment operator that take another type which is to be
 *   converted
 */

#include <iostream>
#include "classes/Point.h"
#include "classes/Number.h"

void do_something(const Point& p)
{
    std::cout << "from_func : " << p << '\n';
}

int main()
{
    Point p1{ 0, 0, 0 };
    Number n1{ 2 };

    // 1 compiler chooses copy assignment op. to convert Number to Point
    // 2 chooses constructor to convert
    // 3 chooses type conversion operator
    p1 = n1;

    // copy assignment operator called then point is constructed from n1
    do_something(n1);

    return 0;
}