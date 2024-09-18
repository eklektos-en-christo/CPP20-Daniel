//
// Created by Εκλεκτός εν Χριστώ on 27/02/2024.
//

/*
 * we can use function templates with other function template overloads and also with
 * normal function overloads, this works
 */

#include <iostream>
#include <cstring>

// template function - will be instantiated if non-pointer arguments are passed
template <typename T>
T maximum(T a, T b)
{
    std::cout << "Non-Pointer template overload called : ";
    return (a > b) ? a : b;
}

// template function overload - will be instantiated if pointer arguments are passed
template <typename T>
T* maximum(T* a, T* b)
{
    std::cout << "Pointer template overload called : ";
    return (*a > *b) ? a : b;
}

// normal overloaded function - will be used if arguments are c-strings
const char* maximum(const char* a, const char* b)
{
    std::cout << "Normal overload called : ";
    return (std::strcmp(a, b) > 0) ? a : b;
}

int main()
{
    int i1{ 39 };
    int i2{ 92 };

    auto p_i1{ &i1 };
    auto p_i2{ &i2 };

    const char* h{ "hello" };
    const char* w{ "world" };

    std::cout << maximum(h, w) << '\n';
    std::cout << maximum(i1, i2) << '\n';
    std::cout << *(maximum(p_i1, p_i2)) << '\n';

    return 0;
}