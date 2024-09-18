//
// Created by Εκλεκτός εν Χριστώ on 28/02/2024.
//

/*
 * decltype - mechanism to deduce the type of an expression - declare type
 *
 * syntax:      decltype(expression)
 *
 * decltype as a trailing return type - we can't use decltype as the return type of
 * the template function directly, the template parameters reside on the right of the
 * function name and decltype will on the left of the function name, compiler won't know
 * about the parameter names until it hits the parameters, to solve this we can use the
 * decltype as the trailing return type after the parameters list
 *
 * syntax:
 *          auto func_name(parameters) -> decltype(expression)
 *          {
 *              func_body
 *          }
 *
 *          // -> decltype(exp) - trailing return type
 *          // auto is a placeholder, not return type deduction
 *
 * by using decltype, we can also separate the declaration and definition without any
 * compiler error
 */

#include <iostream>

// declaration only - works when using decltype
template <typename T, typename P>
auto maximum(T a, P b) -> decltype((a > b) ? a : b);

int main()
{
    int a{ 21 };
    double b{ 39.2 };

    std::cout << maximum(a, b) << '\n';

    std::cout << sizeof(decltype(a > b ? a : b)) << '\n';

    // deducing the type from an expression using decltype and declaring a new variable c
    decltype(a + b) c{ 92 };
    std::cout << sizeof(c) << '\n';

    return 0;
}

// definition
template <typename T, typename P>
auto maximum(T a, P b) -> decltype((a > b) ? a : b)
{
    return (a > b) ? a : b;
}