//
// Created by Εκλεκτός εν Χριστώ on 08/11/2023.
//

#include <iostream>

int main()
{
    short int var1{ 22 };
    short int var2{ 33 };

    std::cout << sizeof(var1) << '\n';
    std::cout << sizeof(var2) << '\n';

    // resulting type is int - implicit conversion to perform the mathematical operation
    auto result{ var1 + var2 };

    std::cout << sizeof(result) << '\n';

    return 0;
}