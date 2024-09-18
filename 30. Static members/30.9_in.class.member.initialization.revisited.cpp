//
// Created by Εκλεκτός εν Χριστώ on 4/7/24.
//

/*
 * ways to initialize the class members:
 * int i;
 * int i=0;
 * int i{};
 * int i{0};
 * custom_type c{};
 */

#include <iostream>

class Integer
{
    int m_int;

public:
    explicit Integer(int i) : m_int{ i }{}
    Integer() = default;
    ~Integer()= default;

    int get_value() const { return m_int; }
    void set_value(int i) { m_int = i; }
};

class Point
{
    double m_x;
    double m_y;
    Integer m_i;

public:
    Point(){};
    Point(double x, double y) : m_x{ x }, m_y{ y }{}
    ~Point() = default;
    void point_info() const
    {
        std::cout << m_x << ", " << m_y << '\n';
        std::cout << m_i.get_value() << '\n';
    }
};

int main()
{
    // junk data in p1
    Point p1;
    p1.point_info();

    return 0;
}