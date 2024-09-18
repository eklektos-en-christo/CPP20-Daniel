//
// Created by Εκλεκτός εν Χριστώ on 5/3/24.
//

/*
 * custom conversion operator can only be implemented as member functions, they don't have
 * a return type, it is deduced by the name of the function
 *
 * mark the conversion functions explicit to avoid implicit conversions and allow only
 * explicit conversions
 *
 * compiler might use overloaded conversion operator or a constructor that converts - call
 * might be ambiguous if both are defined
 */

#include <iostream>
#include "classes/Point.h"
#include "classes/Number.h"

double sum(double a, double b)
{
    return a + b;
}

void use_point(const Point& p)
{
    std::cout << "from func : " << p << '\n';
}

int main()
{
    Number n1{ 82 };
    Number n2{ 90 };

    std::cout << n1 << '\n';
    std::cout << n1 + n1 << '\n';
    std::cout << n2 - n1 << '\n';
    std::cout << n1 * n2 << '\n';
    std::cout << n1 / n2 << '\n';
    std::cout << n1 % n2 << '\n';

    // conversion of n1 and n2 to a double, member operator double() called for conversion
    std::cout << sum(n1, n2) << '\n';

    // conversion of n1 to a Point
    use_point(n1);
    use_point(n2);

    return 0;
}