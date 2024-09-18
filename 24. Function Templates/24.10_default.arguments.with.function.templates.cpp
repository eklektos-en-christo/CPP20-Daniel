//
// Created by Εκλεκτός εν Χριστώ on 28/02/2024.
//

/*
 * we can use default arguments for the template parameters if not passed on the
 * function call, by using this we can also skip passing the return type template
 * argument for return type deduction
 */

#include <iostream>

// double as the default template argument, will be used if not passed on call
template <typename return_type = double, typename T, typename P>
return_type maximum(T a, P b)
{
    return (a > b) ? a : b;
}

int main()
{
    int a{ 291 };
    int b{ 782 };

    // not passed the argument in <>, so default is used - double
    std::cout << sizeof(maximum(a, b)) << '\n';

    // float used as the return type
    std::cout << sizeof(maximum <float> (a, b)) << '\n';

    // int used as the return type
    std::cout << sizeof(maximum <int, double, double> (a, b)) << '\n';

    return 0;
}