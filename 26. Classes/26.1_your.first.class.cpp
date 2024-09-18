//
// Created by Εκλεκτός εν Χριστώ on 3/7/24.
//

/*
 * classes - used to create custom types, class members can't be references
 *
 * #pragma once - lets the compiler create include guards
 */

#include <iostream>

const double PI{ 3.14 };

class Cylinder
{
public:
    // member functions - accessible outside the class
    double volume()
    {
        return PI * base_radius * base_radius * height;
    }

private:
    // member variables - inaccessible outside the class
    double base_radius{};
    double height{};
};

int main()
{
    Cylinder c1{};
    std::cout << c1.volume() << '\n';

    return 0;
}