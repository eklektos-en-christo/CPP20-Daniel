//
// Created by Εκλεκτός εν Χριστώ on 26/02/2024.
//

/*
 * template type deduction - mechanism which the compiler used to deduce the type of template
 * parameters from arguments
 *
 * template parameters - parameters in the template declaration
 * template arguments - passed as a type when the function is called in the <> brackets
 *
 * explicit template arguments - used inside func_name<type>() to force the compiler to use the
 * type as the type for template parameters instead of deducing it from the arguments passed,
 * this also helps when different type of arguments passed, compiler has to do the implicit
 * conversion
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
    int a{ 281 };
    int b{ 892 };

    double d1{ 22.8 };
    double d2{ 82.3 };

    std::string s1{ "Hello" };
    std::string s2{ "World" };

    auto max_s1s2{ max<std::string>(s1, s2) };
    std::cout << max_s1s2 << '\n';

    auto max_ab{ maximum(a, b) };
    std::cout << max_ab << '\n';

    auto max_d1d2{ maximum(d1, d2) };
    std::cout << max_d1d2 << '\n';

    // explicit template argument - to make the int and double work together - implicit
    // conversion by the compiler from double to int
    // compiler generated an int instance
    auto max_ad1{ maximum<int>(a, d1) };
    std::cout << max_ad1 << '\n';

    return 0;
}