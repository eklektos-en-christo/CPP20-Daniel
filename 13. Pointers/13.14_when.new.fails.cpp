//
// Created by Εκλεκτός εν Χριστώ on 30/12/2023.
//

/*
 * when new operator fails - use exception handling or std::nothrow
 *
 * std::nothrow - used as an argument to new operator to tell it not to throw an exception
 * when it fails, this return a nullptr if the allocation fails, then pointer can be checked
 * to see if it is valid or invalid
 */

#include <iostream>

int main()
{
    // terminates the program with an unhandled exception
    /*int* larger_array{ new int[100000000000000000] };*/

    // one solution is to use exception mechanism to handle the exception
    try
    {
        for (std::size_t i{0}; i < 100; ++i)
            int* larger_array{ new int[100000000000000000] };
    }
    catch (std::exception& ex)
    {
        std::cout << "Can't allocate a larger array: " << ex.what() << '\n';
    }

    std::cout << "Program ends well\n";

    // another solution is to use nothrow argument to new operator
    int* large_array{ new(std::nothrow) int[100000000000000000] };

    // checking if nullptr was returned by nothrow
    std::cout << (large_array == nullptr ? "Memory not allocated\n" : "Memory allocated\n");

    std::cout << "Program ends well\n";

    return 0;
}