//
// Created by Εκλεκτός εν Χριστώ on 19/12/2023.
//

/*
 * array bounds: accessing the memory location outside the array bounds cause the bad things
 * to happen, even crash may happen
 */

#include <iostream>

int main()
{
    int my_array[] { 1, 2, 3, 4, 5 };

    // accessing out of bounds location
    /*std::cout << my_array[8] << '\n';*/

    // modifying out of bounds location
    /*my_array[7222424] = 2;*/

    return 0;
}