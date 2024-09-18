//
// Created by Εκλεκτός εν Χριστώ on 17/01/2024.
//

/*
 * one definition rule - there shouldn't be more than one definition for a function in the
 * whole program
 *
 * compilation phase: pre-processing(translation units) > compiling(object files) >
 * linking(binary files)
 *
 * implementations for functions can live in any translation unit, it is not necessary
 * to put the definitions in the same named .cpp file as the header file is
 *
 * linker error - when definition isn't found or definition is available multiple times
 */

#include <iostream>
#include "headers/compare_functions.h"
#include "headers/operations.h"

int main()
{
    std::cout << max(2, 3) << '\n';
    std::cout << min(2, 3) << '\n';
    std::cout << incr_mult(2, 3) << '\n';

    return 0;
}