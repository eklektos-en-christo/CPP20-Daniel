//
// Created by Εκλεκτός εν Χριστώ on 4/13/24.
//

#ifndef PRACTICE_POINT_H
#define PRACTICE_POINT_H

#include <iostream>

namespace Geometry
{
    class Point
    {
    public:
        Point();
        Point(double x, double y);
        void print_info() const { std::cout << m_x << ", " << m_y << '\n'; }

        ~Point();

    private:
        double m_x;
        double m_y;
    };
}

#endif //PRACTICE_POINT_H
