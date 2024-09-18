//
// Created by Εκλεκτός εν Χριστώ on 6/15/24.
//

#include "Shape.h"

Shape::Shape(std::string_view desc)
    : m_description{ desc }
{
    // increase the count when a shape is created
    ++m_count;
}