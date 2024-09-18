//
// Created by Εκλεκτός εν Χριστώ on 25/02/2024.
//

/*
 * recursion - function calling itself
 */

#include <iostream>

std::size_t sum_upto_zero(std::size_t value)
{
    if (value != 0)
        return value + sum_upto_zero(value - 1);
    return 0;
}

int main()
{
    std::cout << sum_upto_zero(5) << '\n';

    return 0;
}