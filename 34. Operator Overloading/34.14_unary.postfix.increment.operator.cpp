//
// Created by Εκλεκτός εν Χριστώ on 5/7/24.
//

/*
 * to distinguish between prefix and postfix operator, we can put a dummy type, namely int in the
 * parameter list of the operator
 *
 * int should be the second parameter in non member implementation of postfix ++
 */

#include <iostream>
#include "classes/Point.h"

int main()
{
    Point p1{ 8, 5 };

    std::cout << p1 << '\n';
    std::cout << p1++ << '\n';
    std::cout << p1 << '\n';

    return 0;
}