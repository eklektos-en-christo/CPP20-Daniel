//
// Created by Εκλεκτός εν Χριστώ on 6/18/24.
//

#ifndef PRACTICE_CIRCLE_H
#define PRACTICE_CIRCLE_H

#include "Shape.h"
#include <iostream>

class Circle : public Shape
{
public:
    Circle() = default;
    Circle(double radius, std::string_view desc);

    virtual double perimeter() const override;
    virtual double surface() const override;

private:
    double m_radius {};

    inline static double PI{ 3.14 };
};

#endif //PRACTICE_CIRCLE_H
