//
// Created by Εκλεκτός εν Χριστώ on 19/12/2023.
//

/*
 * range based for loop: can't be used with decrementing iterator
 * underflow might occur if decrementing loop iterator is an unsigned int
 */

#include <iostream>

int main()
{
    const int count{ 10 };

    for (int i{count}; i > 0; --i)
        std::cout << i << '\n';

    return 0;
}