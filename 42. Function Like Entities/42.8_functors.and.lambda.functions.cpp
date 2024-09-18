//
// Created by Εκλεκτός εν Χριστώ on 7/15/24.
//

/*
 * lambda functions: are modelled using functors behind the scenes, compiler convert a lambda to the class
 * behind the scenes
 */

#include <iostream>

int main()
{
    // compiler generates a functor class behind the scenes and overloads the () operator
    auto result{ [](int a, int b){ return a + b; }(2, 2) };
    std::cout << result << '\n';

    return 0;
}