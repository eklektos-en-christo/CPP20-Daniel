//
// Created by Εκλεκτός εν Χριστώ on 15/10/2023.
//

#include <iostream>

int main()
{
    bool red_light{ true };
    bool green_light{ false };

    if (red_light)
        std::cout << "STOP\n";
    else
        std::cout << "GO THROUGH\n";

    if (green_light)
        std::cout << "GO\n";
    else
        std::cout << "STOP\n";

    std::cout << sizeof(false) << '\n';
    std::cout << true << '\n';
    std::cout << false << '\n';

    // changing the settings of output stream to print the true and false
    std::cout << std::boolalpha;
    std::cout << true << '\n';
    std::cout << false << '\n';

    return 0;
}