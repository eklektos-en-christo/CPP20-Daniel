//
// Created by Εκλεκτός εν Χριστώ on 31/12/2023.
//

/*
 * memory leak - when we loose access to a dynamically allocated memory, solution is to
 * delete the memory when it is of no use
 *
 * double allocation - allocating the pointer twice
 */

#include <iostream>

int main()
{
    // this dynamic memory is leaking, ptr is assigned with new memory address
    int* ptr{ new int{191} };

    // data is not leaking - because we have the variable name to access it
    int data{ 200 };
    ptr = &data;

    std::cout << *ptr << '\n';

    // double allocation - leaked memory, ptr is allocated again in below nested block
    ptr = new int{500};

    {
        // 110 is leaked, never deleted in this scope, nested_ptr dies after this scope
        int* nested_ptr { new int{110} };
    }

    std::cout << *ptr << '\n';

    return 0;
}