//
// Created by Εκλεκτός εν Χριστώ on 6/18/24.
//

/*
 * Interface: an abstract class with only pure virtual function and no member variables, it
 * can be attached to other classes to give them extra features and power
 *
 * to attach: inherit the interface from the other class
 */

#include "polymorphic_levels/StreamInsertable.h"

class Point : public StreamInsertable
{
public:
    Point() = default;
    Point(double x, double y) : m_x{ x }, m_y{ y }
    {
    }

    // overriding the pure virtual function from streamInsertable
    // polymorphic behavior
    virtual void stream_insert(std::ostream& out) const override
    {
        out << "Point{" << m_x << ", " << m_y << "}\n";
    }

private:
    double m_x{};
    double m_y{};
};

int main()
{
    Point point{ 2, 3 };

    // << from streaminsertable calls the stream_insert
    // and stream_insert is called polymorphically from Point class
    // stream_insert from Point prints the Point to ostream
    // that ostream is then returned by operator<< to be printed by std::cout here
    std::cout << point;

    return 0;
}