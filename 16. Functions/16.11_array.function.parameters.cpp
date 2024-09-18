//
// Created by Εκλεκτός εν Χριστώ on 19/01/2024.
//

/*
 * array parameter in function - decays into a pointer
 */

#include <iostream>
#include <array>

// A[] can be replaced with *A - same thing
double sum(double* A, std::size_t count)
{
    double sum{};

    /*std::cout << sizeof(A) << '\n';*/

    for (std::size_t i{0}; i < count; ++i)
    {
        sum += *(A++);
    }

    return sum;
}

int main()
{
    double A[]{ 1.1, 2.8, 3.4, 4.2, 5.7 };

    std::cout << sum(A, std::size(A)) << '\n';

    return 0;
}