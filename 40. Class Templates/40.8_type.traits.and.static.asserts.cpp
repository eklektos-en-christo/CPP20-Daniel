//
// Created by Εκλεκτός εν Χριστώ on 7/9/24.
//

/*
 * we can use type traits and static asserts to perform compile time checks and manipulate the code at
 * compile time
 */

#include "typetraits_staticasserts/BoxContainer.h"
#include <type_traits>

template <class T>
class Point
{
    // using static assert with type traits to validate the type passed on compile time
    static_assert(std::is_arithmetic_v<T>, "Coordinates can only be numbers.");

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
    /*Point<char*> point1;*/        // static assert failed

    Point<int> point2;
    Point<double> point3;

    BoxContainer<Point<int>> point_box;

    return 0;
}