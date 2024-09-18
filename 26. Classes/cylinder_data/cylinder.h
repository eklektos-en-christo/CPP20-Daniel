//
// Created by Εκλεκτός εν Χριστώ on 3/7/24.
//

#ifndef PRACTICE_CYLINDER_H
#define PRACTICE_CYLINDER_H

/*
 * contains prototypes and data members only
 */

#include "constants.h"

class Cylinder
{
public:
    Cylinder() = default;
    Cylinder(double r_param, double h_param);
    double get_radius();
    double get_height();
    void set_radius(double r);
    void set_height(double h);
    double volume();

private:
    double base_radius{};
    double height{};
};

#endif //PRACTICE_CYLINDER_H
