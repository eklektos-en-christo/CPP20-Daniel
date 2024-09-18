//
// Created by Εκλεκτός εν Χριστώ on 19/01/2024.
//

/*
 * size specified to the array parameter in the function is ignored by the compiler,
 * because parameter is a pointer
 */

#include <iostream>

// 100111234342424 is ignored - A is a pointer now
double sum(double A[100111234342424], std::size_t count)
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