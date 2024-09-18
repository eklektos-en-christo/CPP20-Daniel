//
// Created by Εκλεκτός εν Χριστώ on 19/12/2023.
//

/*
 * array: collection of similar type elements, accessed with one identifier
 */

#include <iostream>

int main()
{
    // declaration + initialization, size omitted
    int A[] { 1, 2, 3, 4, 5 };

    // reading from the array
    for (std::size_t i{0}; i < 5; ++i)
        std::cout << A[i] << '\n';

    // writing to the array
    for (std::size_t i{0}; i < 5; ++i)
        A[i] = (i + 1) * 29;

    for (std::size_t i{0}; i < 5; ++i)
        std::cout << A[i] << '\n';

    // calculating the sum of all elements in the array
    int sum{0};
    for (std::size_t i{0}; i < 5; ++i)
        sum += A[i];

    std::cout << "Sum: " << sum << '\n';

    return 0;
}