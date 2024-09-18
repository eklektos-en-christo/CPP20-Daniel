//
// Created by Εκλεκτός εν Χριστώ on 7/18/24.
//

/*
 * raw arrays don't have begin() and end() like collection types have, but they do have pointers as
 * iterators
 *
 * std::begin() and std::end() - allow us to use iterators with raw arrays, they take collection types or
 * raw arrays
 */

#include <iostream>
#include <vector>

int main()
{
    int raw_array[]{ 1, 2, 3, 4, 5 };
    std::vector<int> int_vector{ 11, 22, 33, 44, 55 };

    for (auto iter{ std::begin(int_vector) }; iter != std::end(int_vector); ++iter)
        std::cout << *iter << ' ';
    std::cout << '\n';

    // begin and end taking raw array and returning begin and end ptr to the array
    for (auto iter{std::begin(raw_array)}; iter != std::end(raw_array); ++iter)
        std::cout << *iter << ' ';
    std::cout << '\n';

    return 0;
}