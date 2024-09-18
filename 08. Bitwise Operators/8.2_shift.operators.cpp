//
// Created by Εκλεκτός εν Χριστώ on 27/11/2023.
//

/*
 * Lost data when using the shift operation can't be recovered back, its permanent
 * bit shifting only works with integral types
 */

#include <iostream>
#include <bitset>

int main()
{
    unsigned short int value{ 0xff0u };

    std::cout << value << '\n';
    std::cout << std::bitset<16>(value) << '\n';

    // shifting the bits to right by 1 position
    value = static_cast<unsigned short int>(value >> 1);
    std::cout << value << '\n';
    std::cout << std::bitset<16>(value) << '\n';

    // left shifting the bits by 1 position
    value = static_cast<unsigned short int>(value << 1);
    std::cout << value << '\n';
    std::cout << std::bitset<16>(value) << '\n';

    int mask{ 0xffff };
    for (int count{ 0 }; count < 32; ++count)
    {
        std::cout << std::bitset<64>(mask) << '\n';
        mask = mask << 1;
    }

    return 0;
}