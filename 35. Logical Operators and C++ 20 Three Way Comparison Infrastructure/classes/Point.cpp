//
// Created by Εκλεκτός εν Χριστώ on 5/8/24.
//

#include "Point.h"
#include <cmath>

double Point::length() const
{
    return std::sqrt(pow(m_x - 0, 2) + pow(m_y - 0, 2) * 1.0);
}

/*
bool Point::operator>(const Point& other) const
{
    return (this->length() > other.length());
}

bool Point::operator<(const Point& other) const
{
    return (this->length() < other.length());
}

bool Point::operator>=(const Point& other) const
{
    return (this->length() >= other.length());
}

bool Point::operator<=(const Point& other) const
{
    return (this->length() <= other.length());
}

bool Point::operator==(const Point& other) const
{
    return (this->length() == other.length());
}

bool Point::operator!=(const Point& other) const
{
    return (this->length() != other.length());
}
*/