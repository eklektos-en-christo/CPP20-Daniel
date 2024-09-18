//
// Created by Εκλεκτός εν Χριστώ on 21/10/2023.
//

#include <iostream>

int main()
{
    int number1{ 20 };
    int number2{ 33 };

    std::cout << number1 << '|' << number2 << '\n';
    std::cout << std::boolalpha;

    // using the relational operators to compare the two numbers
    std::cout << "number1 < number2 : " << (number1 < number2) << '\n';
    std::cout << "number1 <= number2 : " << (number1 <= number2) << '\n';
    std::cout << "number1 > number2 : " << (number1 > number2) << '\n';
    std::cout << "number1 >= number2 : " << (number1 >= number2) << '\n';
    std::cout << "number1 == number2 : " << (number1 == number2) << '\n';
    std::cout << "number1 != number2 : " << (number1 != number2) << '\n';

    return 0;
}