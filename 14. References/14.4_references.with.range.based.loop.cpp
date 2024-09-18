//
// Created by Εκλεκτός εν Χριστώ on 01/01/2024.
//

/*
 * to change the data in range based loop, we can take the data by reference
 */

#include <iostream>

int main()
{
    int A[] { 1, 2, 3, 4, 5 };

    // taking each element by reference and changing its value
    for (auto& x : A)
        x *= 100;

    for (auto x : A)
        std::cout << x << ' ';
    std::cout << '\n';

    return 0;
}