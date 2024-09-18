//
// Created by Εκλεκτός εν Χριστώ on 4/12/24.
//

/*
 * same namespaces across multiple files are the same namespace
 */

#include <iostream>
#include "classes/Point.h"
#include "classes/Line.h"
#include "classes/Cylinder.h"

int main()
{
    Geometry::Point point1{ 2.1, 3.6 };
    Geometry::Point point2{ 3.6, 8.1 };
    point1.print_info();

    Geometry::Line line{ point1, point2 };
    line.print_info();

    Geometry::Cylinder cylinder{ 2.1, 8.6 };
    std::cout << "Volume: " << cylinder.volume() << '\n';

    return 0;
}