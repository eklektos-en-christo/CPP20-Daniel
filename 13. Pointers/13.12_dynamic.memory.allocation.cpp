//
// Created by Εκλεκτός εν Χριστώ on 29/12/2023.
//

/*
 * dynamic memory: for runtime use, should be deallocated after the use, it is bad to delete
 * the dynamic memory twice
 *
 * each program has its own memory map when running
 */

#include <iostream>

int main()
{
    // a null initialized pointer
    int* ptr{ nullptr };

    std::cout << ptr << '\n';

    // allocate memory for a single int on heap
    ptr = new int;

    // modifying the heap address, putting 2
    *ptr = 2;

    // accessing the heap memory
    std::cout << *ptr << '\n';

    // deallocating the heap memory
    delete ptr;

    // set the pointer to nullptr after deleting the memory
    ptr = nullptr;

    // initialising the pointer at declaration
    int* ptr_init{ new int{ 99 } };

    std::cout << *ptr_init << '\n';

    delete ptr_init;

    // reusing the pointer
    ptr_init = new int{ 88 };
    std::cout << *ptr_init << '\n';
    delete ptr_init;

    // deleting the pointer 2nd time: program crash
    /*delete ptr_init;*/

    ptr_init = nullptr;

    return 0;
}