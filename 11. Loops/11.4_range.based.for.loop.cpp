//
// Created by Εκλεκτός εν Χριστώ on 18/12/2023.
//

/*
 * Range based for loop: they work on collection types
 */

#include <iostream>

int main()
{
    int my_values[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // each value from my_values in being copied to i and then being printed
    // i is limited to the block of the loop only, can't be used outside
    for (int i : my_values)
        std::cout << "my_values[" << i - 1 << "] = " << i << '\n';

    // specifying the collection inside the for loop
    // auto for the compiler to deduce the type by itself
    for (auto i : { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 })
        std::cout << i << '\n';

    return 0;
}