//
// Created by Εκλεκτός εν Χριστώ on 4/4/24.
//

/*
 * static members - that are not tied to the class object but to the class itself
 * static members are initialized before the program runs, special, they can't be
 * initialized inside the header, they must be initialized in the .cpp source file
 *
 * regular members - are tied to the objects
 *
 * static member can be changed inside a const member function - no error
 */

#include <iostream>
#include <cmath>

class Point
{
public:
    Point() : Point{ 0.0, 0.0 } {}
    Point(double x, double y) : m_x{ x }, m_y{ y }
    {
        ++s_point_count;
        std::cout << "Object no. : " << s_point_count << '\n';
    }
    explicit Point(double xy) : Point{ xy, xy } {}
    Point(const Point& p) : Point{ p.m_x, p.m_y } {}
    ~Point() { --s_point_count; }

    double length() const;
    static std::size_t get_pcount() { return s_point_count; }
    void print_point() { std::cout << &m_x << ", " << &m_y << '\n'; }

private:
    double m_x{};
    double m_y{};

    // this member is shared among all objects, lifetime is not limited to an object
    static std::size_t s_point_count;
};

// init. the static member outside the class or in .cpp file
std::size_t Point::s_point_count{ 0 };

double Point::length() const
{
    return sqrt(pow(m_x - 0, 2) + pow(m_y - 0, 2) * 1.0);
}

int main()
{
    std::cout << Point::get_pcount() << '\n';

    Point p1{2.1, 6.9};
    Point p2{9.7, 4.6};
    Point p3{8.1, 6.3};

    p1.print_point();
    p2.print_point();
    p3.print_point();

    std::cout << p3.get_pcount() << '\n';

    return 0;
}