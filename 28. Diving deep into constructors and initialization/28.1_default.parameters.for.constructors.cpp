//
// Created by Εκλεκτός εν Χριστώ on 3/25/24.
//

/*
 * default parameters : when arguments are not passed to constructors, they can use the default
 * parameters
 */

#include <iostream>

const double PI{ 3.14 };

class Cylinder
{
private:
    double base_radius{ 1 };
    double height{ 1 };

public:
    Cylinder() = default;
    Cylinder(double r_param , double h_param = 8);   // default parameter : 8, 5

    double get_radius() const { return base_radius; };
    double get_height() const { return height; };

    void set_radius(double r_param) { base_radius = r_param; };
    void set_height(double h_param) { this->height = h_param; };

    double volume() const;
};

Cylinder::Cylinder(double r_param, double h_param)
{
    base_radius = r_param;
    height = h_param;
    std::cout << "Parameterized called\n";
}

double Cylinder::volume() const
{
    return PI * base_radius * base_radius * height;
}

int main()
{
    // parameterized constructor has default arguments, so ambiguous call
    // Cylinder c1;

    // uses the default constructor, parameterized take one param, another one is default
    // when no arg is passed, the compiler uses the default constructor which is appropriate in this call
    Cylinder c1;
    std::cout << c1.volume() << '\n';

    return 0;
}