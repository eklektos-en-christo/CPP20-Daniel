//
// Created by Εκλεκτός εν Χριστώ on 28/02/2024.
//

/*
 * type template parameters - typename T, typename P etc., they are type placeholders
 *
 * non type template parameters - int T, double x etc., they are not placeholders for
 * types, they are placeholders for values, we can specify values for types, before
 * C++17 and C++17, we can only use int as non-type template parameter
 */

#include <iostream>

// int threshold - non type template parameter
// typename T - type template parameter
template <int threshold, typename T>
bool is_valid(T collection[], std::size_t size)
{
    T sum{};

    for (std::size_t i{0}; i < size; ++i)
        sum += collection[i];

    return sum > threshold;
}

int main()
{
    double temperatures[]{ 10.0, 20.0, 30.0, 40.0, 50.0 };

    // 200 - value for the placeholder type
    // double - type for the template parameter
    auto result{ is_valid<200, double>(temperatures, std::size(temperatures)) };
    std::cout << result << '\n';

    return 0;
}