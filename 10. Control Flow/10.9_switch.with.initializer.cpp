//
// Created by Εκλεκτός εν Χριστώ on 16/12/2023.
//

/*
 * switch with initializer: allows us to initialize the variable in switch condition
 * initializer is accessible only in switch block
 */

#include <iostream>

int main()
{
    // use of switch with initializer, x is inaccessible outside of switch block
    switch (int x{ 20 }; x)
    {
        case 10:
            std::cout << "x is " << x << '\n';
            break;
        case 20:
            std::cout << "x is " << x << '\n';
            break;
        default:
            std::cout << "????\n";
    }

    return 0;
}