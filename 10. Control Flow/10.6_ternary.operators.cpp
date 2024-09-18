//
// Created by Εκλεκτός εν Χριστώ on 16/12/2023.
//

/*
 * ternary operator: short version of if-else statement
 */

#include <iostream>

int main()
{
    int x{ 2 };
    int y{ 1 };

    // y and x must be of same type or convertible
    // if condition is true, return y otherwise return x
    auto max{ (x < y) ? y : x };
    std::cout << max << '\n';
    std::cout << typeid(max).name() << '\n';

    return 0;
}