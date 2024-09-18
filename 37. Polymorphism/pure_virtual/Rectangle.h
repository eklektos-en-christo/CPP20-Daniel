//
// Created by Εκλεκτός εν Χριστώ on 6/18/24.
//

#ifndef PRACTICE_RECTANGLE_H
#define PRACTICE_RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape
{
public:
    Rectangle() = default;
    Rectangle(double width, double height, std::string_view desc);
    virtual ~Rectangle() = default;

    virtual double perimeter() const override;
    virtual double surface() const override;

private:
    double m_width {};
    double m_height {};
};

#endif //PRACTICE_RECTANGLE_H
