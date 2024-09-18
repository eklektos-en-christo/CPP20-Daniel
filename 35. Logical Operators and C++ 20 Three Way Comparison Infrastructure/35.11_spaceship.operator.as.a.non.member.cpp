//
// Created by Εκλεκτός εν Χριστώ on 5/13/24.
//

/*
 * <=> as a non member - rare case
 * implicit conversions don't work on left operand if the operators are members, solution is
 * to implement them as non members
 */

#include <iostream>
#include "classes/Number.h"

class Point
{
public:
    Point(double x, double y) : m_x{x}, m_y{y}{}

    // point to number conversion operator
    operator Number() const
    {
        std::cout << m_x << " converted to a Number\n";
        return Number{ static_cast<int>(m_x) };
    }

private:
    double m_x{};
    double m_y{};
};

int main()
{
    Point p1{ 8.2, 9.3 };
    Point p2{ 7.5, 6.8 };

    // left operand is implicit Number in Number type, so point is invalid to use
    /*std::cout << (p1 > p2) << '\n';*/

    // works - point is converted to Number first then non member <=> is called
    // if <=> is a member the this code won't work, because left operand of Number<=> is
    // a number and not a Point
    std::cout << (p1 > p2) << '\n';
    std::cout << (p1 == p2) << '\n';

    return 0;
}