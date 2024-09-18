//
// Created by Εκλεκτός εν Χριστώ on 6/7/24.
//

#include "Oval.h"

Oval::Oval(double x_rad, double y_rad, std::string_view desc)
    : Shape{ desc }, m_x_rad{ x_rad }, m_y_rad{ y_rad }
{

}

Oval::~Oval()
{

}