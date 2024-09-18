//
// Created by Εκλεκτός εν Χριστώ on 7/12/24.
//

/*
 * rvalue references : mechanism to extend the lifetime of temporary values(rvalues)
 *
 * they can bind to rvalues, this also prevents from making unnecessary copies
 *
 * syntax: use && insted of & to declare an rvalue reference
 */

#include <iostream>

double add(double a, double b)
{
    return a + b;
}

int main()
{
    int x{2};
    int y{3};

    // rvalue reference to temporary
    auto&& z{ x + y };

    // accessing temporary rvalue through an rvalue reference
    std::cout << z << '\n';

    // works with functions too
    auto&& add_func{ add(2.2, 2.2) };
    std::cout << add_func << '\n';

    auto&& test = int{198};
    std::cout << test << '\n';

    return 0;
}