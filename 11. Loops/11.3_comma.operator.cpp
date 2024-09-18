//
// Created by Εκλεκτός εν Χριστώ on 17/12/2023.
//

/*
 * , -  comma is left to right associative, it returns the value of the right
 * expression by nature when used within parentheses
 */

#include <iostream>

int main()
{
    int increment{ 10 };
    int number1{ 20 };
    int number2{ 30 };
    int number3{ 50 };

    // expression is evaluated from left to right, last expression is returned by ,
    int result = (number1 *= ++increment, number2 - (++increment), number3 += ++increment);

    std::cout << number1 << '\n';
    std::cout << number2 << '\n';
    std::cout << number3 << '\n';
    std::cout << result << '\n';

    return 0;
}