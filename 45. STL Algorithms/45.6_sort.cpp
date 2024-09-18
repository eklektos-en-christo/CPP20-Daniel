//
// Created by Εκλεκτός εν Χριστώ on 8/13/24.
//

/*
 * std::sort - sorts the elements in a collection, the collection should support random access
 * iterators
 *
 *
 */

#include <iostream>
#include <algorithm>
#include <functional>

void print_collection(int* collection, std::size_t size)
{
    for (std::size_t i{0}; i < size; ++i)
        std::cout << collection[i] << ' ';
    std::cout << '\n';
}

int main()
{
    int collection[] { 5, 2, 1, 3, 8, 4 };

    std::sort(std::begin(collection), std::end(collection));

    // sorted collection
    print_collection(collection, std::size(collection));

    // std::greater<>() - () or {} is used to instantiate the std::greater function object
    // <> in std::greater can also be omitted - implicit deduction of the argument's type
    std::sort(std::begin(collection), std::end(collection), std::greater{});

    print_collection(collection, std::size(collection));

    auto less{ [](int a, int b) { return a < b; } };

    // a lambda predicate for sorting in ascending order
    std::sort(std::begin(collection), std::end(collection), less);

    print_collection(collection, std::size(collection));

    return 0;
}