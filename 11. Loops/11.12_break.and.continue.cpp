//
// Created by Εκλεκτός εν Χριστώ on 19/12/2023.
//

/*
 * break: used to break out of the loop immediately
 * continue: used to skip the current iteration and go to next iteration, it may cause
 * infinte loop when used with while and do-while loop(if iterator didn't increment)
 */

#include <iostream>

int main()
{
    // stop when i is 5
    for (std::size_t i{0}; i < 10; ++i)
    {
        if (i == 5)
            break;

        std::cout << i << '\n';
    }   std::cout << '\n';

    // skip one iteration when i is 5
    for (std::size_t i{0}; i < 10; ++i)
    {
        if (i == 5)
            continue;

        std::cout << i << '\n';
    }

    return 0;
}