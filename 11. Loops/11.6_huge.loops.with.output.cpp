//
// Created by Εκλεκτός εν Χριστώ on 18/12/2023.
//

/*
 * std::cout - inside the loop slows down the program
 */

#include <iostream>

int main()
{
    // std::cout making the loop slower
    /*for (int i{0}; i < 1000000; ++i)
        std::cout << i << '\n';*/

    int A[100000]{};

    // runs faster than having a print statement inside the loop
    for (int i{0}; i < 100000; ++i)
        A[i] = i;

    std::size_t i{ 0 };

    // same with the while loop
    while (i < 100000)
    {
        // std::cout << i << '\n';
        ++i;
    }

    return 0;
}