//
// Created by Εκλεκτός εν Χριστώ on 6/29/24.
//

/*
 * we can use class templates to create a single class and then let the compiler generate multiple
 * classes for different types based on the type we provide during object creation
 *
 * syntax:
 *
 * template <class T>
 * classname{
 * };
 *
 * the definitions for template class functions should appear in the header
 * file otherwise compiler error
 *
 * all members are inline by default when using templates, no ODR errors
 *
 * omitting the template argument inside class is OK
 *
 * template instance for a type is generated only once, only the function instances are
 * generated for the object type, if the object is int the int version is generated and if is
 * double then double version is generated of the function, if there is no call to the
 * functions in the code, they are not generated at all
 */

#include <iostream>
#include "first_template/BoxContainer.h"
#include <string>

class Point
{
    friend std::ostream& operator<<(std::ostream& out, const Point& operand);

public:
    Point(double x, double y) : m_x{ x }, m_y{ y }
    {
    }

    Point() : Point(0.0, 0.0)
    {
    }

private:
    double m_x{};
    double m_y{};
};

std::ostream& operator<<(std::ostream& out, const Point& operand)
{
    out << "Point(" << operand.m_x << ", " << operand.m_y << ") ";
    return out;
}

int main()
{
    // template working with multiple types
    BoxContainer<int> int_box;
    int_box.add(2);
    int_box.add(5);
    std::cout << int_box << '\n';

    BoxContainer<double> double_box;
    double_box.add(8.3);
    double_box.add(2.2);
    double_box.add(2.9);
    std::cout << double_box << '\n';

    BoxContainer<Point> point_box;
    point_box.add( Point{2.1, 6.8} );
    point_box.add( Point{8.6, 7.2} );
    std::cout << point_box << '\n';

    BoxContainer<char> char_box;
    char_box.add('h');
    char_box.add('3');
    char_box.add('l');
    char_box.add('l');
    char_box.add('0');
    std::cout << char_box << '\n';

    BoxContainer<std::string> string_box;
    string_box.add("C++");
    string_box.add("Programming");
    std::cout << string_box << '\n';

    std::cout << int_box.size() << '\n';
    std::cout << double_box.size() << '\n';
    std::cout << point_box.size() << '\n';
    std::cout << char_box.size() << '\n';
    std::cout << string_box.size() << '\n';

    return 0;
}