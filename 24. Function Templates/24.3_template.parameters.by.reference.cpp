//
// Created by Εκλεκτός εν Χριστώ on 26/02/2024.
//

/*
 * if both value and reference templates exist for same function, the call will be ambiguous,
 * either value or reference templates can be used
 */

#include <iostream>

// template parameters by value
/*template <typename T>
T maximum(T a, T b)
{
    std::cout << "maximum a : " << &a << '\n';
    std::cout << "maximum b : " << &b << '\n';
    return (a > b) ? a : b;
}*/

// template parameters by reference
template <typename T>
const T& maximum(const T& a, const T& b)
{
    std::cout << "maximum a : " << &a << '\n';
    std::cout << "maximum b : " << &b << '\n';
    return (a > b) ? a : b;
}

int main()
{
    int a{ 2 };
    int b{ 3 };

    maximum(a, b);

    std::cout << "main a : " << &a << '\n';
    std::cout << "main b : " << &b << '\n';

    return 0;
}