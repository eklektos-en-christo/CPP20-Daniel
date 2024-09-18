//
// Created by Εκλεκτός εν Χριστώ on 29/12/2023.
//

/*
 * subtracting the pointers gives the distance between elements in the array
 *
 * std::ptrdiff_t - type used to store pointer difference
 */

#include <iostream>

int main()
{
    int A[] { 1, 2, 3, 4, 5 };

    auto* ptr1{ A };
    auto* ptr2{ A + 4 };

    std::cout << ptr2 - ptr1 << '\n';
    std::cout << ptr1 - ptr2 << '\n';

    // a type to store the pointer difference
    std::ptrdiff_t ptr_diff{ ptr2 - ptr1 };

    std::cout << ptr_diff << '\n';

    std::cout << sizeof(std::ptrdiff_t) << '\n';

    return 0;
}