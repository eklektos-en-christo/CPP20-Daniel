//
// Created by Εκλεκτός εν Χριστώ on 6/7/24.
//

#ifndef PRACTICE_SHAPE_H
#define PRACTICE_SHAPE_H

#include <string>
#include <string_view>
#include <iostream>

class Shape
{
public:
    Shape() = default;
    Shape(std::string_view desc);
    ~Shape();

    virtual void draw() const { std::cout << "Drawing a shape\n"; }

    // an overload of the previous virtual function
    virtual void draw(int color_depth) const
    {
        std::cout << "Drawing a shape with color depth: " << color_depth << '\n';
    }

protected:
    std::string m_description{ "" };
};

#endif //PRACTICE_SHAPE_H
