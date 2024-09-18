//
// Created by Εκλεκτός εν Χριστώ on 4/6/24.
//

/*
 * static member functions - attached to the class itself, they dont have access to the
 * member variables of class directly, but they can access them through the class
 * object, through object they can access the private member variables also
 * , they can directly access the static member variables
 *
 * static member can't have const specifier
 *
 */

#include <iostream>

class Point
{
public:
    Point(double x=0.0, double y=0.0) : m_x{x}, m_y{y} { ++m_count; }

    // static member function
    static std::size_t point_count() { return m_count; }

    static void print_point(const Point& p)
    {
        std::cout << p.m_x << ", " << p.m_y << '\n';
    }

private:
    double m_x{};
    double m_y{};
    static inline std::size_t m_count{0};
};

// necessary to access the m_count through class name
//std::size_t Point::m_count{ 0 };

int main()
{
    std::cout << Point::point_count() << '\n';

    Point p1;

    std::cout << Point::point_count() << '\n';

    return 0;
}