//
// Created by Εκλεκτός εν Χριστώ on 8/15/24.
//

/*
 * STL:
 * algo working on iterator pairs
 * algo working on ranges
 *
 * algo working on ranges with iterator pairs - possible, they are constrained with concepts
 *
 * prefer ranges version of the algorithms
 *
 * iterator pairs - consists of a beginning and an end iterator
 * std::begin and std::end - are function templates, return begin and end iterators, not in pair
 *
 * constrained iterator pairs - they take iterator pairs(container.begin(), container.end())
 * not std::begin and std::end,
 */

#include <iostream>
#include <ranges>
#include <list>
#include <concepts>
#include <vector>
#include <algorithm>

template <typename T>
void print_collection(const T& collection)
{
    for (const auto& element : collection)
        std::cout << element << ' ';
    std::cout << '\n';
}

int main()
{
    std::vector<int> vector{ 2, 1, 4, 3, 8, 7, 5 };

    auto is_odd{ [](int n) { return n % 2 != 0; } };

    // ----------------iterator pairs being used with ranges--------------
    auto is_odd_result{ std::ranges::all_of(vector.begin(), vector.end(), is_odd) };

    if (is_odd_result)
        std::cout << "All elements are odd\n";
    else
        std::cout << "Not all elements are odd\n";

    auto for_each{ [](int& n) { n *= 3; } };

    // ranges with iterator pairs
    std::ranges::for_each(vector.begin(), vector.end(), for_each);

    print_collection(vector);

    std::ranges::sort(vector.begin(), vector.end());

    print_collection(vector);

    std::list<int> list{ 1, 8 , 2 };

    // better errors with ranges algorithms
    /*std::ranges::sort(list.begin(), list.end());*/

    return 0;
}