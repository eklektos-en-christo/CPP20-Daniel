//
// Created by Εκλεκτός εν Χριστώ on 20/12/2023.
//

/*
 * uninitialized array will have junk data
 *
 * leftmost dimension can be omitted when declaring the 2D array, compiler can deduce
 * the size of leftmost dimension, dimensions other than the left can't be omitted
 */

#include <iostream>

int main()
{
    // 2D array, array of 10 boxes, each box contains 10 more boxes inside
    int packages [10][20]{};

    // std::size - to avoid using the hardcoded values
    for (std::size_t i{0}; i < std::size(packages); ++i)
    {
        for (std::size_t j{0}; j < std::size(packages[i]); ++j)
        {
            std::cout << packages[i][j];
        }
        std::cout << '\n';
    }

    std::cout << '\n' << sizeof(packages) << '\n';

    // giving the size of pointers
    std::cout << std::size(packages) << '\n';

    int packages_3d [10][10][10]{};

    for (std::size_t i{0}; i < std::size(packages_3d); ++i)
    {
        for (std::size_t j{0}; j < std::size(packages_3d[i]); ++j)
        {
            std::cout << '(';

            for (std::size_t k{0}; k < std::size(packages_3d[i][j]); ++k)
            {
                std::cout << ' ' << packages_3d[i][j][k] << ' ';
            }

            std::cout << ')' << '\n';
        }
        std::cout << '\n';
    }

    return 0;
}