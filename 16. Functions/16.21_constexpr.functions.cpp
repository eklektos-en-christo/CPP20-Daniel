//
// Created by Εκλεκτός εν Χριστώ on 04/02/2024.
//

/*
 * constexpr functions - those have the potential to be evaluated at the compile time
 *
 * this is done to save some runtime computations
 *
 * constexpr doesn't force but suggest the compiler to do the compile time evaluation
 * if possible
 *
 *
 */

#include <iostream>

constexpr int double_value(int multiplier)
{
    return 2 * multiplier;
}

int main()
{
    // value is made constexpr for the compile time evaluation
    /*constexpr int value{ double_value(8) };*/

    int var{ 20 };

    // this won't be evaluated at compile time - var is a runtime variable
    /*constexpr int result{ double_value(var) };*/

    std::cout << result << '\n';

    return 0;
}