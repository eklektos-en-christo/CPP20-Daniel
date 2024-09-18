//
// Created by Εκλεκτός εν Χριστώ on 6/18/24.
//

#include "Circle.h"

Circle::Circle(double radius, std::string_view desc)
    : Shape(desc), m_radius{ radius }
{

}

double Circle::perimeter() const
{
    std::cout << "Circle::Perimeter : ";
    return 2 * PI * m_radius;
}

double Circle::surface() const
{
    std::cout << "Circle::Surface : ";
    return PI * m_radius * m_radius;
}