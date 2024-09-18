//
// Created by Εκλεκτός εν Χριστώ on 28/02/2024.
//

/*
 * we can use auto for return type of the template function, the definition for the
 * function must come before the use of function call, the compiler uses the return
 * statement to deduce the return type and return statement resides in the definition
 *
 * when using auto with template functions - the largest type passed will be deduced as
 * the return type
 */

#include <iostream>

template <typename T, typename P>
auto maximum(T a, P b)
{
    return (a > b) ? a : b;
}

int main()
{
    // return type is double, double is greater than an int
    std::cout << std::boolalpha;
    std::cout << sizeof(maximum(2, 3.2)) << '\n';

    // we can explicitly specify the type of template parameters - implicit conversion
    std::cout << sizeof(maximum <int, int> (2, 3.2)) << '\n';

    return 0;
}