//
// Created by Εκλεκτός εν Χριστώ on 26/02/2024.
//

/*
 * function templates - used to avoid code repetition when overloading functions
 *
 * function templates are not C++ code, they are blueprint for creating functions
 * by the compiler, compiler doesn't generate functions from templates which are
 * never called
 *
 * once generated function is not generated again by the compiler
 *
 * passing pointers as the argument to template functions might result in disaster
 */

#include <iostream>
#include <string>

template <typename T>
T maximum(T a, T b)
{
    return (a > b) ? a : b;
}

int main()
{
    int x{ 22 };
    int y{ 28 };

    auto max{ maximum(x, y) };
    std::cout << max << '\n';

    std::string s1{ "Hello" };
    std::string s2{ "World" };

    auto max_str{ maximum(s1, s2) };
    std::cout << max_str << '\n';

    return 0;
}