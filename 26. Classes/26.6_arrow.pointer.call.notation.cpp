//
// Created by Εκλεκτός εν Χριστώ on 3/7/24.
//

/*
 * -> : used to access an object through pointer instead of . operator
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
    // stack object
    Cylinder c1{ 5, 10 };
    std::cout << c1.volume() << '\n';

    // heap object
    Cylinder* p_c2{ new Cylinder{ 2, 4 } };

    // ugly way of accessing an object through a pointer
    std::cout << (*p_c2).volume() << '\n';

    // better way
    std::cout << p_c2->volume() << '\n';

    // pointer to a stack object
    Cylinder* p_c3{ &c1 };
    std::cout << p_c3->volume() << '\n';

    // release the memory
    delete p_c2;

    return 0;
}