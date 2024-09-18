//
// Created by Εκλεκτός εν Χριστώ on 16/11/2023.
//

/*
 * explicit type conversions: initiated by the programmer
 */

#include <iostream>

int main()
{
    double x{ 923.3 };
    double y{ 968.4 };

    int sum = x + y;
    std::cout << sum << '\n';
    std::cout << sizeof(sum) << '\n';

    // explicit cast using static_cast, <resulting type> (x) - input type
    auto sum2 = static_cast<int>(x) + static_cast<int>(y);
    std::cout << sum2 << '\n';
    std::cout << sizeof(sum2) << '\n';

    auto sum3 = static_cast<int>(x + y);
    std::cout << sum3 << '\n';
    std::cout << sizeof(sum3) << '\n';

    // old c-style cast
    auto sum4 = (int) (x + y);
    std::cout << sizeof(sum4) << '\n';
    std::cout << sum4 << '\n';

    return 0;

}