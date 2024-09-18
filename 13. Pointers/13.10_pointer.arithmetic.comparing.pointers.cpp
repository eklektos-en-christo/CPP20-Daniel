//
// Created by Εκλεκτός εν Χριστώ on 29/12/2023.
//

/*
 * the comparison takes place between the address values stored in the pointers
 */

#include <iostream>

int main()
{
    int A[] { 1, 2, 3, 4, 5 };

    auto* ptr1{ A };
    auto* ptr2{ A };

    std::cout << std::boolalpha;

    // comparing the pointers
    std::cout << (ptr1 == ptr2) << '\n';

    return 0;
}