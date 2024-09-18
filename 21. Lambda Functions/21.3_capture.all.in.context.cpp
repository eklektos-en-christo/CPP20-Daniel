//
// Created by Εκλεκτός εν Χριστώ on 25/02/2024.
//

/*
 * capture everything by value : use = in the [], by default the values captured by value
 * are non-mutable in the lambda
 * capture everything by reference : use & in the []
 */

#include <iostream>

int main()
{
    int a{ 6 };
    int b{ 8 };

    // mutable needed to make the lambda mutable, immutable by default when capturing by
    // value
    auto capt_by_val
    {
        [=]() mutable
        {
            ++a; ++b;
        }
    };

    capt_by_val();
    std::cout << a << ' ' << b << '\n';

    auto capt_by_ref
    {
        [&]()
        {
            ++a; ++b;
        }
    };

    capt_by_ref();
    std::cout << a << ' ' << b << '\n';

    return 0;
}