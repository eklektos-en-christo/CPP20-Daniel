//
// Created by Εκλεκτός εν Χριστώ on 4/13/24.
//

#include "Point.h"
#include "Number.h"
#include "Car.h"

    Point::Point(double x, double y, int data) : m_x{x}, m_y{y}, point_data{ new int{data} }
    {
    }

    Point::~Point()
    {
        delete point_data;
    }

    // this can be used by the compiler in conversion of Number to point
    Point::Point(const Number& num)
        : Point{ static_cast<double>(num.get_wrapped_int()),
                 static_cast<double>(num.get_wrapped_int()), 0 }
    {
        std::cout << "Using the Point constructor to convert\n";
    }

    void Point::operator=(const Car& right_car)
    {
        m_x = m_y = right_car.get_speed();
        *point_data = right_car.get_speed();
    }

    // can be used by compiler to convert number to a point
    void Point::operator=(const Number& n)
    {
        m_x = m_y = n.get_wrapped_int();
        std::cout << "Using the copy assignment operator to convert\n";
    }