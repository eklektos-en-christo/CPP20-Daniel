//
// Created by Εκλεκτός εν Χριστώ on 8/16/24.
//

#ifndef PRACTICE_POINT_H
#define PRACTICE_POINT_H

#include <iostream>
#include <cmath>

class Point
{
private:
    friend std::ostream& operator<< (std::ostream& out, const Point& point);
    double length() const { return std::sqrt((pow(m_x - 0, 2) + pow(m_y - 0, 2) * 1.0)); }

public:
    Point();
    Point(double x, double y);
    ~Point();
    bool operator==(const Point& other) const;
    std::partial_ordering operator<=>(const Point& right) const;

    double m_x;
    double m_y;
};

#endif //PRACTICE_POINT_H
