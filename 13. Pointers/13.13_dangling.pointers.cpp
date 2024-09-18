//
// Created by Εκλεκτός εν Χριστώ on 29/12/2023.
//

/*
 * dangling pointer - that doesn't point to a valid memory address
 *
 * when multiple pointers pointing to the same address, before accessing the other pointers,
 * check the master pointer if it is non-null
 */

#include <iostream>

int main()
{
    // solution is to give nullptr as a value to the pointer being declared here
    int* uninit_ptr;

    std::cout << uninit_ptr << '\n';

    // using the uninitialized pointer - program crash
    /*std::cout << *uninit_ptr << '\n';*/

    // dereference only when pointer is not null
    if (uninit_ptr != nullptr)
        std::cout << *uninit_ptr << '\n';

    int* deleted_ptr{ new int{ 2 } };

    std::cout << *deleted_ptr << '\n';
    delete deleted_ptr;
    deleted_ptr = nullptr;

    // crash - accessing the deleted memory
    /*std::cout << *deleted_ptr << '\n';*/

    int* ptr1{ new int{ 232 } };
    int* ptr2{ ptr1 };

    std::cout << *ptr1 << '\n';
    std::cout << *ptr2 << '\n';

    delete ptr1;
    ptr1 = nullptr;

    // crash - same memory is deleted by ptr1
    std::cout << *ptr2 << '\n';

    // check the master pointer, then dereference the slave pointers
    if (ptr1 != nullptr)
        std::cout << *ptr2 << '\n';
    else
        std::cout << "Invalid memory access\n";

    return 0;
}