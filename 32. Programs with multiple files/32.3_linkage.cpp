//
// Created by Εκλεκτός εν Χριστώ on 4/17/24.
//

/*
 * linkage determines the visibility of a name across the translation units, it is
 * associated with a name, like variable, function etc.
 *
 * internal linkage :
 * by default, const global varibles have internal linkage, accessible only in that
 * TU only
 *
 * external linkage : accessible in multiple translation units, function are default
 * to external linkage, non const global variables have external linkage too
 *
 * local variable in function have no linkage
 *
 * to use the global non const variable in another translation unit : we need to declare
 * that variable in another unit as extern with an initializer
 *
 * we don't need to mark the functions as extern to use them in other TUs
 */

#include <iostream>

void simple_function()
{
    int local_variable{ 10 };
    std::cout << "Address of age : " << &local_variable << '\n';
}

const double global_const{ 9.8 };

int global_variable{ 8 };

// compiler needs to see the declaration - definition resides in other file
void print_global_from_other_file();

int main()
{
    simple_function();

    // local_variable has no linkage, only accessible inside simple_function
    /*std::cout << local_variable << '\n';*/

    // global constants have internal linkage
    std::cout << "Global const : " << global_const << '\n';

    // accessing from the same TU
    std::cout << global_variable << '\n';

    // accessing from another TU
    print_global_from_other_file();

    return 0;
}