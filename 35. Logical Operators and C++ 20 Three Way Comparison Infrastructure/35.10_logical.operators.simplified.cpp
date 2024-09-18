//
// Created by Εκλεκτός εν Χριστώ on 5/13/24.
//

/*
 *  in cpp20 use one <=> and one == to simplify the implementation of logical operators
 */

#include <iostream>
#include "classes/Number.h"

int main()
{
    Number n1{ 2 };
    Number n2{ 8 };

    std::cout << std::boolalpha;

    std::cout << (n1 < n2) << '\n';
    std::cout << (3 < n2) << '\n';
    std::cout << (n1 < 3) << '\n';

    std::cout << (n1 > n2) << '\n';
    std::cout << (3 > n2) << '\n';
    std::cout << (n1 > 3) << '\n';

    std::cout << (n1 == n2) << '\n';
    std::cout << (3 == n2) << '\n';
    std::cout << (n1 == 3) << '\n';

    std::cout << (n1 != n2) << '\n';
    std::cout << (3 != n2) << '\n';
    std::cout << (n1 != 3) << '\n';

    std::cout << (n1 <= n2) << '\n';
    std::cout << (3 <= n2) << '\n';
    std::cout << (n1 <= 3) << '\n';

    std::cout << (n1 >= n2) << '\n';
    std::cout << (3 >= n2) << '\n';
    std::cout << (n1 >= 3) << '\n';

    return 0;
}