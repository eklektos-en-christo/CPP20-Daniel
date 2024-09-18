//
// Created by Εκλεκτός εν Χριστώ on 22/12/2023.
//

/*
 * pointer to const: a pointer pointing to a const data, data can't be changed
 * through the pointer
 *
 * const pointer: a constant pointer, pointer can't be assigned with another
 * address
 *
 * const pointer to const data: data or pointer value can't be changed
 *
 * const pointer to non const: pointer value can't be changed, but data it points
 * to can be changed through it
 *
 * if const if left of the *, then data is const, not pointer
 * if const if right of the *, the pointer itself is const, not data
 */

#include <iostream>

int main()
{
    int non_const_data{ 1 };

    const int* pointer_to_non_const_data{ &non_const_data };
    /**pointer_to_non_const_data = 2;*/

    int* const const_pointer_to_non_const_data{ &non_const_data };
    /*const_pointer_to_non_const_data = nullptr;*/

    const int const_data{ 1 };

    const int* const const_pointer_to_const_data{ &const_data };
    /*const_pointer_to_const_data = nullptr;*/
    /**const_pointer_to_const_data = 2;*/

    int* const const_pointer{ &non_const_data };
    *const_pointer = 2;

    int protected_data{ 1 };
    const int* non_const_pointer{ &protected_data };
    std::cout << *non_const_pointer << '\n';
    protected_data = 2;
    std::cout << *non_const_pointer << '\n';

    /*int* ptr_int{ &const_data };*/

    return 0;
}