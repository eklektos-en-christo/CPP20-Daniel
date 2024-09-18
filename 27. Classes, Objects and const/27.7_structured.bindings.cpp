//
// Created by Εκλεκτός εν Χριστώ on 3/21/24.
//

/*
 * structured bindings - allows us to declare multiple variables and bind them to the
 * elements of a collection or any other class that supports this. in this way we can
 * decompose a complex data structure into  its constituent parts
 *
 * member variables must be public for structured bindings
 */

#include <iostream>

struct Point
{
    double x {};
    double y {};
};

void print_point(const Point p)
{
    std::cout << "x : " << p.x << '\n';
    std::cout << "y : " << p.y << '\n';
}

int main()
{
    // call to constructor, x and y members are copied to a and b, no & appended to auto
    auto [a, b]{ Point{} };

    std::cout << a << ' ' << b << '\n';

    // initial point
    Point p{ 2.2, 8.6 };

    // structured binding using a reference - & necessary for this
    auto& [x, y]{ p };

    // changes to the Point
    p.x = 0.1;
    p.y = 0.9;

    // changes reflected in x and y too - references
    std::cout << x << ' ' << y << '\n';
    print_point(p);

    // capturing a structured binding in the lambda
    auto func{ [x]() { std::cout << "x in lambda : " << x << '\n'; } };
    func();

    return 0;
}