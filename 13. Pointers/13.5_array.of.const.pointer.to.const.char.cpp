//
// Created by Εκλεκτός εν Χριστώ on 22/12/2023.
//

/*
 * make const pointer to const char to avoid changing the data
 */

#include <iostream>

int main()
{
    const char* students[]
            {   "hello",
                "World"
            };

    std::cout << *students[0];

    // const char array can't be modified
    /**students[0] = 'J';*/

    return 0;
}