//
// Created by Εκλεκτός εν Χριστώ on 4/13/24.
//

#ifndef PRACTICE_CYLINDER_H
#define PRACTICE_CYLINDER_H

namespace Geometry
{
    class Cylinder
    {
    public:
        Cylinder(double radius, double height);
        double volume() const { return PI * m_radius * m_radius * m_height; }

    private:
        inline static const double PI { 3.14 };
        double m_radius{1};
        double m_height{1};
    };
}

#endif //PRACTICE_CYLINDER_H
