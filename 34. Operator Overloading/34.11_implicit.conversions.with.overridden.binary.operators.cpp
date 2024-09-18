//
// Created by Εκλεκτός εν Χριστώ on 5/7/24.
//

/*
 * the left operand of the binary operator is never implicitly converted when operator is
 * a member of the class, the first operand is the implicit object, if we pass other type
 * than the implicit type, we get compiler error
 *
 * if implicit conversion is desired then overload the binary operators as standalone functions
 */

#include <iostream>
#include "classes/Number.h"

int main()
{
    Number n1{ 87 };

    std::cout << n1 << '\n';

    // works, 3 converted to a Number
    std::cout << n1 + 3 << '\n';

    // operator+'s left operand is a Number, we passed an int - error
    // no implicit conversion allowed from 3 to Number, operator+ is a member
    /*std::cout << 3 + n1 << '\n';*/

    // works - operator- is a non member and implicit conversions are allowed
    std::cout << 1 - n1 << '\n';

    return 0;
}