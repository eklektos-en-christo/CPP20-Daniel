//
// Created by Εκλεκτός εν Χριστώ on 3/7/24.
//

/*
 * constructor : special class functions, called when objects are created, usually used to
 * initialize the member variables
 */

#include <iostream>

const double PI{ 3.14 };

class Cylinder
{
public:
    Cylinder()
    {
        base_radius = 2.0;
        height = 2.0;
    }

    Cylinder(double r_param, double h_param)
    {
        base_radius = r_param;
        height = h_param;
    }

    double volume()
    {
        return PI * base_radius * base_radius * height;
    }

private:
    double base_radius{};
    double height{};
};

int main()
{
    // constructor initializes the members with 2.0
    Cylinder c1;
    std::cout << c1.volume() << '\n';

    // constructor with parameters called
    Cylinder c2{ 3.2, 4.9 };
    std::cout << c2.volume() << '\n';

    return 0;
}