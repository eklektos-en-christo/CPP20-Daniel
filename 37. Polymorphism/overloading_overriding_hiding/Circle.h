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

//    virtual void draw(int color_depth) const
//    {
//        std::cout << "Drawing a circle with color depth: " << color_depth << '\n';
//    }

    virtual void draw(int color_depth, std::string_view color) const override
    {
        std::cout << "Drawing an oval with color depth " << color_depth;
        std::cout << " and color " << color << '\n';
    }
};

#endif //PRACTICE_CIRCLE_H
