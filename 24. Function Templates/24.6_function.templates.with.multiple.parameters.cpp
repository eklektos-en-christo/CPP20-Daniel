//
// Created by Εκλεκτός εν Χριστώ on 28/02/2024.
//

/*
 * function templates with multiple template parameters - the return type depends upon
 * the order of arguments passed to the function, it might change as the arguments'
 * position will change.
 *
 * a better way to solve this is to use separate template parameter for return type, on
 * the function call, the template argument for return type should be passed, otherwise
 * compiler won't be able to deduce the return type - compiler error
 */

#include <iostream>

template <typename return_type, typename T, typename P>

return_type maximum(T a, P b)
{
    return (a > b) ? a : b;
}

int main()
{
    // int is passed as the template argument - necessary for return type deduction
    // T and P will be deduced from the arguments
    auto result{ maximum <int> (2, 5.8) };

    std::cout << sizeof(result) << '\n';

    return 0;
}