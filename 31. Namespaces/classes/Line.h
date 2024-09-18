//
// Created by Εκλεκτός εν Χριστώ on 4/13/24.
//

#ifndef PRACTICE_LINE_H
#define PRACTICE_LINE_H

#include "Point.h"

namespace Geometry
{
    class Line
    {
    public:
        Line(const Point& start, const Point& end);
        void print_info() const
        {
            std::cout << "Line:\n";
            std::cout << "Start: ";
            m_start.print_info();
            std::cout << "End: ";
            m_end.print_info();
        }

    private:
        Point m_start;
        Point m_end;
    };
}

#endif //PRACTICE_LINE_H
