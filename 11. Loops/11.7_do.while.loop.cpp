//
// Created by Εκλεκτός εν Χριστώ on 18/12/2023.
//

/*
 * do while loop: runs first, then checks the condition, it is guaranteed to run at
 * least once, even if the condition if false
 */

#include <iostream>

int main()
{
    int x{ 20 };
    std::size_t count{ 21 };

    // runs only once and then stops, condition is false
    do
    {
        std::cout << count << '\n';
        ++count;
    } while (count < x);

    return 0;
}