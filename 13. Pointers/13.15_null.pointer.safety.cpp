//
// Created by Εκλεκτός εν Χριστώ on 31/12/2023.
//

/*
 * making sure that pointers we are working with have valid addresses
 *
 * using a if statement, we can check a pointer against nullptr value
 *
 * we can call delete on a pointer containing a nullptr, this won't harm the program
 */

#include <iostream>

int main()
{
    int* null_ptr{};

    // null_ptr will be evaluated as true if it contains a valid address
    // null_ptr will be evaluated as false if it contains no/invalid address
    if (null_ptr)
    {
        std::cout << "Valid pointer with " << null_ptr << '\n';
    }
    else
    {
        std::cout << "Invalid pointer with " << null_ptr << '\n';
    }

    return 0;
}