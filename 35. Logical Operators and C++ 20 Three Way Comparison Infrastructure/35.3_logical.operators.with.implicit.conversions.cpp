//
// Created by Εκλεκτός εν Χριστώ on 5/9/24.
//

/*
 * implicit conversions are not going to work for the left operand for binary operator when
 * implemented as member functions
 *
 * solution is to implement the operators as non member functions
 */

#include <iostream>
#include "classes/Number.h"

int main()
{
    Number n1{ 91 };
    Number n2{ 71 };

    // works - member operator< takes Number on both sides
    std::cout << (n1 < n2) << '\n';

    std::cout << (2 < n2) << '\n';

    std::cout << (n1 > 7) << '\n';

    return 0;
}