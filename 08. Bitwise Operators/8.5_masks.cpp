//
// Created by Εκλεκτός εν Χριστώ on 02/12/2023.
//

#include <iostream>
#include <bitset>

int main()
{
    unsigned char mask{ 0b00100000 };

    // set the 5th bit to 1 in 0b00000000 binary literal
    std::cout << std::bitset<8>(0b00000000 | mask) << '\n';

    // check if the 5th bit is ON or OFF in 0b00001100 binary literal
    std::cout << std::bitset<8>(0b00001100 & mask) << '\n';

    // reset the fifth bit to OFF if it is ON in 0b00100000 binary literal
    std::cout << std::bitset<8>((0b00100000 & (~mask))) << '\n';

    // if the fifth bit is ON then set it to OFF
    std::cout << std::bitset<8>((0b10100110 ^ mask)) << '\n';

    return 0;
}