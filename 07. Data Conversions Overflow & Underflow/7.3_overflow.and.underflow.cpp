//
// Created by Εκλεκτός εν Χριστώ on 18/11/2023.
//

/*
 * Overflow: feeding the data more than a type can handle
 * Underflow: vice versa of overflow
 */

#include <iostream>

int main()
{
    unsigned char data{ 255 };

    // overflow
    for (int i{ 0 }; i <= 20; ++i)
        std::cout << static_cast<int>(data) << ' ';
    std::cout << '\n';

    data = 0;

    // underflow
    for (int i{ 0 }; i <= 20; ++i) {
        --data;
        std::cout << static_cast<int>(data) << ' ';
    }
    std::cout << '\n';

    return 0;
}