//
// Created by Εκλεκτός εν Χριστώ on 7/12/24.
//

/*
 * lvalues - they have address and can be stored for a long time in memory
 *
 * rvalues - they exist for a short time and are destroyed when not needed
 */

#include <iostream>

int test() { return 0; }

int main()
{
    // lvalues
    int x{ 2 };
    int y{ 5 };

    // x+y is rvalue, can't take address of it
    /*std::cout << &(x+y) << '\n';*/

    // test return an rvalue, can't take the address of it
    /*std::cout << &test() << '\n';*/

    return 0;
}