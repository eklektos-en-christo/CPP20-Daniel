//
// Created by Εκλεκτός εν Χριστώ on 02/12/2023.
//

#include <iostream>
#include <iomanip>

int main()
{
    const unsigned int red_color{ 0xFF000000 };
    const unsigned int green_color{ 0x00FF0000 };
    const unsigned int blue_color{ 0x0000FF00 };
    const unsigned int alpha{ 0x000000FF };

    unsigned int my_color{ 0xABCDFF00 };

    std::cout << std::hex <<std::showbase;

    // get the red, green, blue color and the transparency values
    std::cout << ((my_color & red_color) >> 24) << '\n';
    std::cout << ((my_color & green_color) >> 16) << '\n';
    std::cout << ((my_color & blue_color) >> 8) << '\n';
    std::cout << ((my_color & alpha) >> 0) << '\n';

    std::cout << std::dec << '\n';

    // in decimal
    std::cout << ((my_color & red_color) >> 24) << '\n';
    std::cout << ((my_color & green_color) >> 16) << '\n';
    std::cout << ((my_color & blue_color) >> 8) << '\n';
    std::cout << ((my_color & alpha) >> 0) << '\n';

    return 0;
}