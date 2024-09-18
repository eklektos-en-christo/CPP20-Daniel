//
// Created by Εκλεκτός εν Χριστώ on 6/18/24.
//

#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(double width, double height, std::string_view desc)
    : Shape(desc), m_width{ width }, m_height{ height }
{

}

double Rectangle::perimeter() const
{
    std::cout << "Rectangle::Perimeter : ";
    return (2 * m_width + 2 * m_height);
}

double Rectangle::surface() const
{
    std::cout << "Rectangle::Surface : ";
    return m_width * m_height;
}