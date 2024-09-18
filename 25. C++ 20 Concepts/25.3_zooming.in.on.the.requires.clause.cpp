//
// Created by Εκλεκτός εν Χριστώ on 3/4/24.
//

/*
 * four kind of requirements we can use with requires clause:
 * simple requirements
 * nested   ,,
 * compound     ,,
 * type requirements
 *
 * simple : expressions only checked for valid syntax
 *
 * nested : requires expression inside requires clause, checks if the expression is true
 *
 * compound : involves multiple expressions
 */

#include <iostream>
#include <concepts>
#include <type_traits>

// simple requirement
template <typename T>
concept tiny_type = requires (T a)
{
    // only enforces syntax, expression doesn't evaluate
    sizeof(T) <= 1223;

    // nested requirement - enforcing the expression to be checked
    requires sizeof(T) == 8;
};

tiny_type auto add(tiny_type auto a, tiny_type auto b)
{
    return a + b;
}

template <typename T>
concept addable = requires (T a, T b)
{
    // compound requirement - multiple statements
    { a + b } noexcept -> std::convertible_to<int>;
};

addable auto add_something(addable auto a, addable auto b)
{
    return a + b;
}

int main()
{
    int a{ 1 };
    int b{ 9 };

    // int passed, concept requires the size <=1, no expression evaluated in the concept
    /*std::cout << add(a, b) << '\n';*/


    // size of an int is not 8Bytes - unsatisfied concept
    /*std::cout << add(a, b) << '\n';*/

    // concept satisfied - true and 2 are convertible to an int
    add_something(true, 2);

    // error cstring is not convertible to an int
    /*add_something("a", b);*/

    return 0;
}