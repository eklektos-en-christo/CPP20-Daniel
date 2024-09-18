//
// Created by Εκλεκτός εν Χριστώ on 17/12/2023.
//

/*
 * multiple declarations in for loop: multiple variables can be declared in for loop
 * declarations before first semicolon and after second semicolon are separated by comma
 * in middle of both semicolons contain the controller condition
 */

#include <iostream>

int main()
{
    // 3 declarations before first semicolon, declarations must be of same type
    // declarations are separated by commas, type name is used only once size_t
    for (std::size_t i{0}, j{9}, k{0}; i < 10; --j, ++i, ++k)
    {
        std::cout << i << ' ' << j << ' ' << k << '\n';
    }

    return 0;
}