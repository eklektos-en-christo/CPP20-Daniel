//
// Created by Εκλεκτός εν Χριστώ on 4/1/24.
//

/*
 * move constructor - steals data from temporary objects
 *
 * std::move - used to convert the lvalue into rvalue which enables the move semantics
 */

#include <iostream>

class Point
{
    double* p_x{};
    double* p_y{};

    void invalidate() { p_x = nullptr; p_y = nullptr; }

public:
    Point(double x, double y) : p_x{ new double{x} }, p_y{ new double{y} }
    {
    }

    ~Point()
    {
        delete p_x; delete p_y;
    }

    Point(const Point& src_point);
    Point(Point&& src_point) noexcept;

    void set_x(double x) { *p_x = x; }
    void set_y(double y) { *p_y = y; }
    double* get_x() const { return p_x; }
    double* get_y() const { return p_y; }

    void print_point() const
    {
        std::cout << "(" << *p_x << ", " << *p_y << ")\n";
    }
};

// performs a deep copy
Point::Point(const Point& src_point)
    : p_x{ new double{ *src_point.get_x() } },
      p_y{ new double{ *src_point.get_y() } }
{
    std::cout << "Copy constructor called\n";
}

// move constructor
Point::Point(Point&& src_point) noexcept
    : p_x{src_point.get_x()}, p_y{src_point.get_y()}
{
    // making the temporary null - stealing, dest. owns the resources now
    // if we don't make the temporary null, it will release its resources through destructor
    // and the destination object will be left with dangling pointers
    // another way of invalidating is to set up the private steal functions in the
    // source object and call them in the initializer list instead of get_x and get_y
    src_point.invalidate();
    std::cout << "Move constructor called\n";
}

int main()
{
    Point p1{ 1.6, 6.2 };
    p1.print_point();

    // creating a copy from a temporary Person object - no moving happens
    // to make the resource move from temporary to p2 we need move constructor
    /*Point p2{ std::move(Point{ 8, 10 }) };
    p2.print_point();*/

    // move constructor is called - resources are owned by p3 now
    Point p3{ std::move(Point{ 8, 10 }) };
    p3.print_point();

    return 0;
}