//
// Created by Εκλεκτός εν Χριστώ on 3/7/24.
//

/*
 * put the class in header file, header contains only member declarations
 * definitions for member functions should go in a cpp file
 * main should be free from extra clutter
 */

#include <iostream>
#include "cylinder_data/cylinder.h"

int main()
{
    Cylinder c1{ 1.9, 2.6 };
    c1.set_radius(2.0);
    c1.set_height(2.0);

    std::cout << c1.get_radius() << '\n';
    std::cout << c1.get_height() << '\n';
    std::cout << c1.volume() << '\n';

    return 0;
}