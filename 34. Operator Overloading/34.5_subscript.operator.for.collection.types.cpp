//
// Created by Εκλεκτός εν Χριστώ on 4/27/24.
//

/*
 * using the [] with arrays
 */

#include "classes/Scores.h"

int main()
{
    Scores s{"Science"};
    s.print_info();
    s[10] = 2;
    s.print_info();

    for (std::size_t i{0}; i < 20; ++i)
    {
        s[i] = i + 23.2;
    }

    for (std::size_t i{0}; i < 20; ++i)
    {
        std::cout << s[i] << ' ';
    }
    std::cout << '\n';

    // a const object - using subscript operator
    const Scores s2{ "Mathematics" };

    s2.print_info();

    for (std::size_t i{0}; i < 20; ++i)
    {
        std::cout << s2[i] << ' ';
    }
    std::cout << '\n';

    return 0;
}