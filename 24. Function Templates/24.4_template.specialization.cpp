//
// Created by Εκλεκτός εν Χριστώ on 27/02/2024.
//

/*
 * template specialization - mechanism to tell the compiler for a template function, if we
 * pass a specific type and we don't want the default implementation, we want our own custom
 * implementation for that type
 *
 * syntax:
 *      template<>
 *      return_type func_name<our_type>(our_type...);
 *
 *      our_type - specialized for our_type, explicit template argument
 */

#include <iostream>
#include <cstring>

template <typename T>
T maximum(T a, T b)
{
    std::cout << "\ndefault template called\n";
    return (a > b) ? a : b;
}

// specialized template for const char* type
template <>
const char* maximum/*<const char*> - not necessary*/(const char* a, const char* b)
{
    std::cout << "\nspecialization called\n";
    return (std::strcmp(a, b) > 0) ? a : b;
}

int main()
{
    double d1{ 22.38 };
    double d2{ 98.27 };

    std::cout << maximum(d1, d2) << '\n';

    const char* h{ "hello" };
    const char* w{ "wello" };

    // calls the specialized template
    std::cout << maximum(h, w) << '\n';

    return 0;
}