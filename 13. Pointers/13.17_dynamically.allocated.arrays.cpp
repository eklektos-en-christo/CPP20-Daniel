//
// Created by Εκλεκτός εν Χριστώ on 31/12/2023.
//

/*
 * range based for loop and std::size don't work with dynamically allocated arrays
 * static arrays are allocated on stack and dynamic on heap
 */

#include <iostream>
#include <array>

int main()
{
    std::size_t size{ 20 };

    // dynamically allocated array of doubles of size 20
    double* p_salaries{ new double[size] };

    // nothrow version of new
    double* p_salaries_nothrow{ new(std::nothrow) double[size]{} };

    // printing using pointer arithmetic & []
    for (std::size_t i{0}; i < size; ++i)
    {
        std::cout << p_salaries[i] << " : " << *(p_salaries + i) << '\n';
    }

    int static_array[10]{};

    std::cout << std::size(static_array) << '\n';

    // std::size - not working with pointer
    /*std::cout << std::size(p_salaries) << '\n';*/

    // for each loop doesn't work with pointer
    /*for (auto x : p_salaries[0])*/

    for (auto x : static_array)
        std::cout << x << ' ';
    std::cout << '\n';

    // for each doesn't work with pointer
    /*for (auto x : p_salaries)
        std::cout << x;*/

    return 0;
}