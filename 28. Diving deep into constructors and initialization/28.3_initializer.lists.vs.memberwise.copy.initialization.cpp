//
// Created by Εκλεκτός εν Χριστώ on 3/26/24.
//

/*
 * initalizer list : in this init. the object is initialized at the time of creation, this avoids
 * unnecessary copies, initialization happens in single step instead of two steps
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
    Cylinder(double r_param , double h_param)
            : base_radius{ r_param }, height(h_param)       // initializer list
    {

    }

    double get_radius() const { return base_radius; };
    double get_height() const { return height; };

    void set_radius(double r_param) { base_radius = r_param; };
    void set_height(double h_param) { this->height = h_param; };

    double volume() const;
};

double Cylinder::volume() const
{
    return PI * base_radius * base_radius * height;
}

int main()
{
    Cylinder cylinder{ 5, 5 };
    std::cout << cylinder.volume() << '\n';

    return 0;
}