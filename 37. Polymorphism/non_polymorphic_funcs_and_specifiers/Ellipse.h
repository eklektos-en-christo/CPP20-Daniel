//
// Created by Εκλεκτός εν Χριστώ on 6/15/24.
//

#ifndef PRACTICE_ELLIPSE_H
#define PRACTICE_ELLIPSE_H

#include "Shape.h"
#include <string_view>

class Ellipse : public Shape
{
public:
    Ellipse();
    Ellipse(double x_rad, double y_rad, std::string_view desc);
    virtual ~Ellipse() = default;

private:
    void draw() const
    {
        std::cout << "Ellipse::draw() called: " << m_description << '\n';
    }

public:
    void func() const
    {
        std::cout << "Ellipse::func() called: " << m_description << '\n';
    }

private:
    double m_x_radius {};
    double m_y_radius {};
};

#endif //PRACTICE_ELLIPSE_H
