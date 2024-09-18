//
// Created by Εκλεκτός εν Χριστώ on 16/12/2023.
//

/*
 * C++ allows us to declare the initializers in if statement, initializer is accessible
 * in else statement also, initializer remains visible inside the if else and not
 * outside of the if else statement, it makes sense to initialize the variable in the
 * scope in which it is needed
 */

#include <iostream>

int main()
{
    // if with initializer, x is limited to if else block only
    if (int x{ 2 }; x < 0)
        std::cout << x << " is less than 0\n";
    else
        std::cout << x << " is greater than 0\n";

    return 0;
}