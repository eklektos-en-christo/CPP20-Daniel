//
// Created by Εκλεκτός εν Χριστώ on 28/02/2024.
//

/*
 * auto function templates : a syntax to simplify the template functions, behind the
 * scenes, the compiler will generate the actual template function and from that a
 * template instance will be generated according to the arguments passed to the
 * function
 */

#include <iostream>

// function templates behind the scenes
auto sum(auto a, auto b)
{
    return a + b;
}

int main()
{
    std::cout << sum(20, 20.2) << '\n';

    return 0;
}