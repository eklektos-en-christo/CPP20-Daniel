//
// Created by Εκλεκτός εν Χριστώ on 8/16/24.
//

#include "Point.h"

Point::Point(double x, double y) : m_x{x}, m_y{y} {}
Point::Point() : Point{0.0,0.0} {}
Point::~Point() = default;

bool Point::operator==(const Point &other) const
{
    return this->length() == other.length();
}

std::partial_ordering Point::operator<=>(const Point &right) const
{
    if (length() > right.length())
        return std::partial_ordering::greater;
    else if (length() < right.length())
        return std::partial_ordering::less;
    else if (length() == right.length())
        return std::partial_ordering::equivalent;
    else
        return std::partial_ordering::unordered;
}

std::ostream& operator<< (std::ostream& out, const Point& point)
{
    out << '[' << point.m_x << ", " <<  point.m_y << ", " << point.length() << ']';
    return out;
}