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

protected:
    std::string m_description{ "" };
};

#endif //PRACTICE_SHAPE_H
