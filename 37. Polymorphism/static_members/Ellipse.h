//
// Created by Εκλεκτός εν Χριστώ on 6/15/24.
//

#ifndef PRACTICE_ELLIPSE_H
#define PRACTICE_ELLIPSE_H

#include "Shape.h"
#include <string_view>

class Ellipse : public Shape
{
public:
    Ellipse();
    Ellipse(double x_rad, double y_rad, std::string_view desc);
    virtual ~Ellipse() { --m_count; }

    virtual int get_count() const override { return m_count; }

    // we want a separate count for derived class, so creating static m_count for ellipse
    inline static int m_count{ 0 };

private:
    double m_x_radius {};
    double m_y_radius {};
};

#endif //PRACTICE_ELLIPSE_H
