//
// Created by Εκλεκτός εν Χριστώ on 8/19/24.
//

/*
 * range factories : producing views out of thin air :D, they themselves generate sequences and don't
 * require containers or other ranges to work with them and produce views
 */

#include <iostream>
#include <ranges>

int main()
{
    // iota - generates infinite sequence from the given element
    auto infinite{ std::views::iota(1) };

    /*
    for (auto i : infinite)
        std::cout << "Infinite: " << i << '\n';*/

    // iota has also an upper bound parameter, upper bound is not included
    for (auto i : std::views::iota(1, 11))
        std::cout << "Upper bound: " << i << '\n';

    // filter the first 30 elements from infinite sequence
    for (auto i : std::views::iota(1) | std::views::take(30))
        std::cout << "Take: " << i << '\n';

    // raw function composition also works
    for (auto i : std::views::take(std::views::iota(1), 5))
        std::cout << "Raw composition: " << i << '\n';

    return 0;
}