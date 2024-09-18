//
// Created by Εκλεκτός εν Χριστώ on 14/02/2024.
//

/*
 * get the address of maximum number in an array
 */

#include <iostream>

const double* find_max_address(const double* scores, std::size_t count)
{
    std::size_t max_index{};
    double max_num{};

    for (std::size_t i{0}; i < count; ++i)
    {
        if (scores[i] > max_num)
        {
            max_num = scores[i];
            max_index = i;
        }
    }

    return &scores[max_index];
}

int main()
{
    double array[]{ 0.2, 1.2, 0.1, 0.0 };

    std::cout << *(find_max_address(array, std::size(array))) << '\n';

    return 0;
}