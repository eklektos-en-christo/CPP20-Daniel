//
// Created by Εκλεκτός εν Χριστώ on 6/7/24.
//

#ifndef PRACTICE_CIRCLE_H
#define PRACTICE_CIRCLE_H

#include "Oval.h"
#include <string_view>

class Circle : public Oval
{
public:
    Circle() = default;
    Circle(double radius, std::string_view desc);
    ~Circle();

    virtual void draw() const override
    {
        std::cout << "Drawing a cirle with radius: " << get_x_rad();
        std::cout << ", " << m_description << '\n';
    }
};

#endif //PRACTICE_CIRCLE_H
