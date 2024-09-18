//
// Created by Εκλεκτός εν Χριστώ on 19/12/2023.
//

/*
 * std::size - returns the size of the array in bytes
 */

#include <iostream>

int main()
{
    int A[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // getting the size of the array using std::size
    auto count{ std::size(A) };

    for (std::size_t i{0}; i < count; ++i)
        std::cout << A[i] << ' ';
    std::cout << '\n';

    // manually getting the size of the array
    auto size{ sizeof(A)/sizeof(A[0]) };

    for (std::size_t i{0}; i < size; ++i)
        std::cout << A[i] << ' ';
    std::cout << '\n';

    // easiest way is to use a range based loop
    for (auto x : A)
        std::cout << x << ' ';
    std::cout << '\n';

    return 0;
}