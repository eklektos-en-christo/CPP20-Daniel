//
// Created by Εκλεκτός εν Χριστώ on 02/12/2023.
//

/*
 * they perform the bitwise operation and put back the result into the variable
 */

#include <iostream>
#include <bitset>

int main()
{
    unsigned char a{ 0x1 };

    std::cout << "Before shift: " << std::bitset<8>(a) << '\n';
    a <<= 6;        // perform the left shift and store the result in the same variable
    std::cout << "After  shift: " << std::bitset<8>(a) << '\n';

    return 0;
}