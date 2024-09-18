//
// Created by Εκλεκτός εν Χριστώ on 19/12/2023.
//

/*
 * we can declare the variable inside the range based for loop, variable will be limited to
 * the scope of the for loop only
 */

#include <iostream>

int main()
{
    // variable initialization inside range based for loop, can't be used outside the loop
    for (auto doubler{2}; auto x : {1, 2, 3, 4, 5, 6, 7, 8, 9, 10})
        std::cout << x * doubler << '\n';

    return 0;
};