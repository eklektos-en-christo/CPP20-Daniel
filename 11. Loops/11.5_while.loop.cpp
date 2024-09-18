//
// Created by Εκλεκτός εν Χριστώ on 18/12/2023.
//

/*
 * while loop: same as for loop, used where number of iterations are not known
 * beforehand, only the condition at which to stop is known
 */

#include <iostream>

int main()
{
    // iterator declared outside the loop
    std::size_t count{ 0 };
    int i{ 10 };

    while (count < i)
    {
        std::cout << count + 1 << " : I love C++\n";
        ++count;
    }

    return 0;
}