//
// Created by Εκλεκτός εν Χριστώ on 16/12/2023.
//

/*
 * anything that is not zero in C++ is considered as true
 */

#include <iostream>

int main()
{
    int total_items{ 10 };

    // 10 is considered as true
    if (total_items)
        std::cout << "Total items in bag: " << total_items << '\n';

    return 0;
}