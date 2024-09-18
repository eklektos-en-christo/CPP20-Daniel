//
// Created by Εκλεκτός εν Χριστώ on 7/9/24.
//

/*
 * we can constrain the templates using concepts
 * they can be attached to functions as well
 * function definitions outside the class requires the concept specification also using requires
 */

#include <iostream>
#include "templates_concepts/BoxContainer.h"
#include <concepts>

// using concept to constrain the type instead of static asserts
// the Point should have arithmetic values only
template <class T> requires std::is_arithmetic_v<T>
class Point
{
public:
    Point() = default;
    Point(T x, T y) : m_x{ x }, m_y{ y } {}

    friend std::ostream& operator<<(std::ostream& out, const Point<T> operand)
    {
        out << "Point(" << operand.m_x << ", " << operand.m_y << ')';
        return out;
    }

private:
    T m_x{};
    T m_y{};
};

int main()
{
    Point<int> point1;

    // concept failure - type is not an arithmetic
    /*Point<char*> point2;*/

    BoxContainer<Point<int>> point_box;

    return 0;
}