//
// Created by Εκλεκτός εν Χριστώ on 9/18/24.
//

module;

#include <iostream>
#include <string_view>

export module print;

// import the math module in this module and export it from this module
// this will allow the importers to use print module as well as math module
export import math;

export void print_name(std::string_view name)
{
    std::cout << name << '\n';
}