//
// Created by Εκλεκτός εν Χριστώ on 6/7/24.
//

#ifndef PRACTICE_OVAL_H
#define PRACTICE_OVAL_H

#include "Shape.h"
#include <string_view>

class Oval : public Shape
{
public:
    Oval() = default;
    Oval(double x_rad, double y_rad, std::string_view desc);
    ~Oval();

    virtual void draw() const
    {
        std::cout << "Drawing an oval with radius: " << m_x_rad << ", " << m_y_rad;
        std::cout << ", " << m_description << '\n';
    }

public:
    double get_x_rad() const { return m_x_rad; }
    double get_y_rad() const { return m_y_rad; }

private:
    double m_x_rad{ 0.0 };
    double m_y_rad{ 0.0 };
};

#endif //PRACTICE_OVAL_H
