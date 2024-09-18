//
// Created by Εκλεκτός εν Χριστώ on 8/13/24.
//

/*
 * std::copy - copies data from one collection to another
 */

#include <iostream>
#include <algorithm>

void print_collection(int* collection, std::size_t size)
{
    for (std::size_t i{0}; i < size; ++i)
    {
        std::cout << collection[i] << ' ';
    }
    std::cout << '\n';
}

int main()
{
    int src[] { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int dest[] { 4, 5, 6, 7, 8,  9, 10 };

    // last element is not included: 3
    std::copy(std::begin(src), std::begin(src) + 2, std::begin(dest));

    print_collection(dest, std::size(dest));

    auto predicate{ [](int n) {
        if (n % 2 != 0)
            return true;
        else
            return false;
    }};

    // copy only if the current element is an odd number
    std::copy_if(std::begin(src), std::end(src), std::begin(dest), predicate);

    print_collection(dest, std::size(dest));

    return 0;
}