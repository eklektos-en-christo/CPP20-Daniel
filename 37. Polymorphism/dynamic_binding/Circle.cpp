//
// Created by Εκλεκτός εν Χριστώ on 6/7/24.
//

#include "Circle.h"

Circle::Circle(double radius, std::string_view desc)
    : Oval{ radius, radius, desc }
{

}

Circle::~Circle() {}