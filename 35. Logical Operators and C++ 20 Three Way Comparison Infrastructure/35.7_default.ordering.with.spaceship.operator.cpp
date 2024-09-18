//
// Created by Εκλεκτός εν Χριστώ on 5/11/24.
//

/*
 * syntax for implementing the <=> operator:
 *
 *          auto operator<=>(const class&) const = default;
 *
 *          default - compiler generates the operator for us, also == and != when
 *          defaulted, so by using the defaulted <=> we have all 6 logical operators
 *
 *          const - to restrict the object being modified by the operator
 *          auto - compiler deduces the return type based on operands
 *
 *          return type can be one of three - strong, weak and partial ordering
 *          compiler will generate > >= < <= from <=>
 *          implicit conversions will also work and compiler might re-write operands
 */

#include <iostream>
#include "classes/Item.h"

int main()
{
    Item i1{ 1,6,7 };
    Item i2{ 2, 1, 8 };

    std::cout << std::boolalpha;
    // compiler converts these operators to <=>
    // (operand <=> operand) operator 0     - operator here is any of the 6 operators
    std::cout << (i1 > i2) << '\n';
    std::cout << ((i1 <=> i2) > 0) << '\n';     // like this the compiler converts

    std::cout << (i1 >= i2) << '\n';
    std::cout << (i1 <= i2) << '\n';
    std::cout << (i1 < i2) << '\n';
    std::cout << (i1 == i2) << '\n';
    std::cout << (i1 != i2) << '\n';

    // implicit conversions work
    std::cout << (2 < i2) << '\n';
    std::cout << (i1 > 2) << '\n';
    std::cout << (3 != i2) << '\n';

    return 0;
}