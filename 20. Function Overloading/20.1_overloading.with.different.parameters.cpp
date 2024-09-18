//
// Created by Εκλεκτός εν Χριστώ on 20/02/2024.
//

/*
 * overloads are based on the order of parameter, number of parameters and types of
 * the parameters
 *
 * name of the function and type of the parameters are used to distinguish between
 * two functions
 */

#include <iostream>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

double max(double a, double b)
{
    return (a > b) ? a : b;
}

int main()
{
    std::cout << max(2, 3) << '\n';
    std::cout << max(2.2, 3.3) << '\n';

    return 0;
}