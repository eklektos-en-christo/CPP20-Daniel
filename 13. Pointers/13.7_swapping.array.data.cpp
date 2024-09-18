//
// Created by Εκλεκτός εν Χριστώ on 22/12/2023.
//

/*
 * instead of copying each individual elements between arrays, we can use pointers to copy
 * the address of both arrays' first element
 *
 * we can't point one array to another, pointers can be used to do that
 */

#include <iostream>

int main()
{
    int A[] { 1, 2, 3, 4, 5 };
    int B[] { 11, 12, 13, 14, 15 };

    for (auto a : A)
        std::cout << a << ' ';
    std::cout << '\n';

    for (auto b : B)
        std::cout << b << ' ';
    std::cout << '\n';

    // taking addresses of A and B in pointers
    int* ptr{ nullptr };
    auto* ptr_a{ A };
    auto* ptr_b{ B };

    // swapping pointers
    ptr = A;
    ptr_a = ptr_b;
    ptr_b = ptr;

    for (std::size_t i{ 0 }; i < std::size(A); ++i)
    {
        std::cout << ptr_a[i] << ' ';
    }
    std::cout << '\n';

    for (std::size_t i{ 0 }; i < std::size(A); ++i)
    {
        std::cout << ptr_b[i] << ' ';
    }
    std::cout << '\n';

    return 0;
}