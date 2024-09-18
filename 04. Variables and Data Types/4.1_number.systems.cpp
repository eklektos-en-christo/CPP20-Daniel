//
// Created by Εκλεκτός εν Χριστώ on 12/10/2023.
//

#include <iostream>

int main()
{
    // different representations of the same number in the source code
    int number1{ 15 };          // decimal
    int number2{ 017 };         // octal
    int number3{ 0x0F };        // hexadecimal
    int number4{ 0b00001111 };  // binary

    std::cout << number1 << '\n';
    std::cout << number2 << '\n';
    std::cout << number3 << '\n';
    std::cout << number4 << '\n';

    return 0;
}