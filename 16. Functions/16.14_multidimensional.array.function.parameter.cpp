//
// Created by Εκλεκτός εν Χριστώ on 19/01/2024.
//

/*
 *
 */

#include <iostream>

double sum_2d(const double A[][3], std::size_t size)
{
    double sum{};

    for (std::size_t i{0}; i < size; ++i)
    {
        for (std::size_t j{0}; j < size; ++j)
        {
            sum += A[i][j];                 // one notation
            /*sum += *(*(A + i) + j);*/         // ptr arithmetic notation
        }
    }
    return sum;
}

int main()
{
    double A[][3]
    {
        {2.1, 2.2, 2.3},
        {2.1, 2.2, 2.3},
        {2.1, 2.2, 2.3}
    };

    std::cout << sizeof(A) << '\n';
    std::cout << sum_2d(A, std::size(A)) << '\n';

    return 0;
}