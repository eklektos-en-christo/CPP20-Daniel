//
// Created by Εκλεκτός εν Χριστώ on 7/15/24.
//

/*
 * mixin capturing : when capturing by value and reference at the same time, the capture all syntax for
 * value or reference should come first, otherwise compiler error,
 *
 * once the capture all syntax is used for value or reference, we can't use it again inside the capture
 * list to capture other data by value/reference
 */

#include <iostream>

int main()
{
    int a{ 8 };
    int b{ 9 };
    int c{ 10 };
    int d{ 11 };

    // capture all by value and d by refrence
    auto func1{ [=, &d](){}};

    // capture all by reference and b by value
    auto func2{ [&, b](){} };

    // capture all syntax should come first - incorrect
    /*auto func3{ [a, c, &](){} };*/

    // capture all syntax should come first - correct
    auto func4{ [&, a, c](){} };

    // a and = are by value, not allowed
    /*auto func5{ [a, &b, =](){} };*/

    // can't use the same capture again when once it is used
    // capture by value is used(=), again b is by value - not correct
    /*auto func6{ [=, &a, b](){} };*/

    return 0;
}