//
// Created by Εκλεκτός εν Χριστώ on 3/7/24.
//

/*
 * setters : member functions to write data to the member variables
 * getters : member function to read data from the member variables
 */

#include <iostream>

const double PI{ 3.14 };

class Cylinder
{
public:
    // default constructor - explicitly marked
    Cylinder() = default;

    Cylinder(double r_param, double h_param)
    {
        base_radius = r_param;
        height = h_param;
    }

    // getters
    auto get_radius()
    {
        return base_radius;
    }

    auto get_height()
    {
        return height;
    }

    // setters
    void set_radius(double r)
    {
        base_radius = r;
    }

    void set_height(double h)
    {
        height = h;
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
    Cylinder c1;
    c1.set_radius(2.0);
    c1.set_height(2.0);

    std::cout << c1.get_radius() << '\n';
    std::cout << c1.get_height() << '\n';
    std::cout << c1.volume() << '\n';

    return 0;
}