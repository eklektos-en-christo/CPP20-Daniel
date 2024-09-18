//
// Created by Εκλεκτός εν Χριστώ on 16/10/2023.
//

#include <iostream>

int main()
{
    char character1{ 'C' };
    char character2{ '+' };
    char character3{ '+' };

    std::cout << character1 << character2 << character3 << '\n';

    std::cout << sizeof(char) << '\n';

    char value{ 70 };
    std::cout << value << '\n';

    // forcing the output stream to print the char as an integer
    std::cout << static_cast<int>(value) << '\n';

    return 0;
}