//
// Created by Εκλεκτός εν Χριστώ on 04/02/2024.
//

/*
 * consteval functions : this guarantees that function will be evaluated at compile
 * time, it forces the compile time evaluation, compiler error if evaluation fails
 *
 */

#include <iostream>

consteval int multiply(int multiplier)
{
    return multiplier * multiplier;
}

int main()
{
    int value1{ multiply(22) };
    std::cout << value1 << '\n';

    int runtime_var{ 91 };

    // multiply failed - consteval function requires constant expressions
    // runtime_var is a runtime variable, not a compile time variable
    /*int value2{ multiply(runtime_var) };*/

    return 0;
}