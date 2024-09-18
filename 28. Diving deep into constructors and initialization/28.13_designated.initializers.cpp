//
// Created by Εκλεκτός εν Χριστώ on 4/3/24.
//

/*
 * designated initializers - syntax to specify which member variables we want to initialize
 * with the values in an aggregate initialization
 *
 * value must be given in order the members are layed down in the aggregate struct/class
 */

#include <iostream>

struct Component
{
    double x;
    double y;
    double z;
};

void print_comp(const Component& c)
{
    std::cout << "x : " << c.x << '\n';
    std::cout << "y : " << c.y << '\n';
    std::cout << "z : " << c.z << '\n';
    std::cout << "-----\n";
}

int main()
{
    // init. with designated initializers
    Component c1{ 1, 2, 3 };
    print_comp(c1);

    // designated initializer
    Component c2{ .x = 1, .y = 2, .z = 3  };
    print_comp(c2);

    // we can skip the members, skipped will be initialized to their default values
    Component c3{ .y = 2 };
    print_comp(c3);

    // order can't be changed - not recommended
    Component c4{ .z = 3, .x = 1 };
    print_comp(c4);

    return 0;
}