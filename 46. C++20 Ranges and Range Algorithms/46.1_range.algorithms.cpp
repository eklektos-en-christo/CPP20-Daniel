//
// Created by Εκλεκτός εν Χριστώ on 8/14/24.
//

/*
 * there are two versions of algorithms in STL: iterator pair version and ranges version
 *
 * Ranges : helps to specify the containers to algorithms without the beginning and the end iterator
 */

#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>

template <typename T>
void print_collection(const T& collection)
{
    auto it{ collection.begin() };

    while (it != collection.end())
    {
        std::cout << *it << ' ';
        ++it;
    }
    std::cout << '\n';
}

int main()
{
    std::vector<int> vector{ 1, 8, 9, 2, 3, 5, 4 };

    auto is_odd{ [](int n){ return (n % 2) != 0; } };

    // all_of here lives in ranges namespace and different from std::all_of
    auto result{ std::ranges::all_of(vector, is_odd) };

    if (result)
        std::cout << "All number are odd in vector\n";
    else
        std::cout << "Not all number are odd in vector\n";

    auto func{ [](int& n) { n *= 2 + 1; } };

    // working on a collection without specifying the first and last element, - ranges
    auto result_1{ std::ranges::for_each(vector, func) };

    print_collection(vector);

    std::ranges::sort(vector);

    print_collection(vector);

    // returns an iterator to the found element
    auto result_2{ std::ranges::find_if(vector, is_odd) };

    if (result_2 != std::end(vector))
        std::cout << "Vector has at least one odd number: " << *result_2 << '\n';
    else
        std::cout << "Vector doesn't have odd numbers\n";

    // each element is iterated over by the ostream_iterator and then put into std::cout for
    // printing, each element is separated with " "
    std::ranges::copy(vector, std::ostream_iterator<int>(std::cout, " "));

    return 0;
}