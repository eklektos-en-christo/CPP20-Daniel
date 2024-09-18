//
// Created by Εκλεκτός εν Χριστώ on 14/02/2024.
//

/*
 * function would return a copy of the local variables if the return type is just
 * auto, auto& is necessary to deduce a true reference
 */

#include <iostream>

auto& max_ref(int& a, int& b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main()
{
    int a{ 2 };
    int b{ 9 };

    std::cout << b << '\n';

    // deducing a true reference
    auto& ref = max_ref(a, b);
    ++ref;

    // ref_again is a copy and not a reference to b
    auto ref_again = max_ref(a, b);
    ++ref_again;

    std::cout << b << '\n';

    return 0;
}