//
// Created by Εκλεκτός εν Χριστώ on 6/15/24.
//

#include "Ellipse.h"

Ellipse::Ellipse()
    : Ellipse(0, 0, "No Description")
{

}

Ellipse::Ellipse(double x_rad, double y_rad, std::string_view desc)
    : Shape(desc), m_x_radius{ x_rad }, m_y_radius{ y_rad }
{
}