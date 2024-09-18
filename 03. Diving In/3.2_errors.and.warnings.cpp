//
// Created by Εκλεκτός εν Χριστώ on 04/10/2023.
//

#include <iostream>

int main()
{
    // compile time error : missing semicolon - introduced on purpose
    /*std::cout << "COMPILE TIME ERROR\n"*/

    // warning - division by zero
    int i{ 10/0 };

    // runtime error - unexpected output
    std::cout << i << '\n';

    return 0;
}