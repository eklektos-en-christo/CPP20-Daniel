//
// Created by Εκλεκτός εν Χριστώ on 4/18/24.
//

#include <iostream>
#include "32.6_inline.variables.and.functions.h"    // duplicate code

inline int length{ 2 };

inline void some_func()
{
    std::cout << length << ", address : " << &length << '\n';
}

void print_length_tu2()
{
    std::cout << "Printing from TU2 : ";
    some_func();
    test_from_header();
}