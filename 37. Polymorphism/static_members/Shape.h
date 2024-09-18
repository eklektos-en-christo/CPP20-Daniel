//
// Created by Εκλεκτός εν Χριστώ on 6/15/24.
//

#ifndef PRACTICE_SHAPE_H
#define PRACTICE_SHAPE_H

#include <iostream>
#include <string>
#include <string_view>

class Shape
{
public:
    Shape() : Shape("No Description") {}
    Shape(std::string_view desc);
    virtual ~Shape() { --m_count; }

    void draw() const { std::cout << "Shape::draw() called: " << m_description << '\n'; }
    virtual int get_count() const { return m_count; }

    inline static int m_count{ 0 };

protected:
    std::string m_description {};
};

#endif //PRACTICE_SHAPE_H
