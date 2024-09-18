//
// Created by Εκλεκτός εν Χριστώ on 28/02/2024.
//

/*
 * decltype(auto) - to avoid duplication of return statement expression and decltype
 * expression as a trailing return type, we use decltype(auto)
 *
 * limitation - we can't split declaration and definition when using decltype auto,
 * compiler has to see the return statement for return type deduction
 */

#include <iostream>

// decltype auto - to avoid the duplication of return expression
template <typename T, typename P>
decltype(auto) maximum(T a, P b)
{
    return (a > b) ? a : b;
}

int main()
{
    std::cout << maximum(2, 8) << '\n';

    return 0;
}