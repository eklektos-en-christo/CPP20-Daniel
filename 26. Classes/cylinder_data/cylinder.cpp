//
// Created by Εκλεκτός εν Χριστώ on 3/7/24.
//

/*
 * implementation for all cylinder.h functions
 */

#include "cylinder.h"

Cylinder::Cylinder(double r_param, double h_param)
{
    base_radius = r_param;
    height = h_param;
}

double Cylinder::get_radius()
{
    return base_radius;
}

double Cylinder::get_height()
{
    return height;
}

void Cylinder::set_radius(double r)
{
    base_radius = r;
}

void Cylinder::set_height(double h)
{
    height = h;
}

double Cylinder::volume()
{
    return PI * base_radius * base_radius * height;
}