//
// Created by Εκλεκτός εν Χριστώ on 4/13/24.
//

#include "Point.h"

namespace Geometry
{
    Point::Point(double x, double y) : m_x{x}, m_y{y} {}
    Point::Point() : Point{0.0,0.0} {}
    Point::~Point() = default;
}