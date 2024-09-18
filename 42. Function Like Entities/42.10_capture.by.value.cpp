//
// Created by Εκλεκτός εν Χριστώ on 7/15/24.
//

/*
 * lambda capture by value:
 * the capture list values are created as data members in the functors and initialized in the functor's
 * constructor
 *
 * only the values that are being used in the lambda are created as members in the functor class
 *
 * data captured by value can't be modified directly, for that the lambda should be mutable specified
 */

#include <iostream>

int main()
{
    int a {2};
    int b {10};
    double d1 {2.221};
    double d2 {3.89};

    // capturing by value
    auto lambda1{ [a, b](int c, int d) mutable {
        // not allowed for copied values, the operator() generated for this lambda is const specified
        // so it can't modify any values, that's why the modifications are not allowed
        /*std::cout << ++a << '\n';*/

        // works now, the operator() generated is non const because of mutable keyword
        ++a;
        std::cout << a << '\n';
        std::cout << b << '\n';
        std::cout << c << '\n';
        std::cout << d << '\n';
    }};

    lambda1(1, 9);

    return 0;
}