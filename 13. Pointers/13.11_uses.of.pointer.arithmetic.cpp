//
// Created by Εκλεκτός εν Χριστώ on 29/12/2023.
//

#include <iostream>

int main()
{
    int A[] { 1, 2, 3, 4, 5 };
    int B[] { 6, 7, 8, 9, 0 };

    auto* ptr_a{ A };
    auto* ptr_b{ B };

    auto* temp_ptr{ ptr_a };
    ptr_a = ptr_b;
    ptr_b = temp_ptr;

    // using pointer arithmetic to access and print the data
    for (std::size_t i{0}; i < std::size(A); ++i)
        std::cout << *(ptr_a + i) << '\n';
    std::cout << '\n';

    for (std::size_t i{0}; i < std::size(A); ++i)
        std::cout << *(ptr_b + i) << '\n';
    std::cout << '\n';

    return 0;
}