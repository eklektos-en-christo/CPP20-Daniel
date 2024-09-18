//
// Created by Εκλεκτός εν Χριστώ on 22/12/2023.
//

/*
 * Array name can be treated as the pointer to the first element of the array,
 * you can't assign to an array name, it is like a constant pointer
 *
 * we can't use a pointer to deduce the size of the array
 *
 * array name decays into a pointer when used in an expression
 *
 * we can use the [] with pointer name
 *
 * don't use std::size with a raw pointer
 */

#include <iostream>

int main()
{
    int A[]{ 1, 2, 3, 4, 5 };

    // array name decayed into a pointer and address is copied into ptr
    int* ptr{ A };

    // A decayed into a pointer which contains address of the first element
    std::cout << A << '\n';
    // ptr contains the address of the first element of array A
    std::cout << ptr << '\n';
    // & returns the address of first element in A
    std::cout << &A[0] << '\n';

    // A decayed into a pointer, dereferencing will return the first element of A
    std::cout << *A << '\n';
    std::cout << A[0] << '\n';
    std::cout << *ptr << '\n';
    // equivalent of dereferencing a pointer
    std::cout << ptr[0] << '\n';

    // can't assign to an array name
    /*A = ptr;*/

    // A contains some info that is used by std::size to deduce the size of an array
    std::cout << std::size(A) << '\n';

    // ptr is a pointer, doesn't contain anything except an address, error
    /*std::cout << std::size(ptr) << '\n';*/

    return 0;
}