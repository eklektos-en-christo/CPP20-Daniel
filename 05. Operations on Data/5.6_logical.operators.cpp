//
// Created by Εκλεκτός εν Χριστώ on 25/10/2023.
//

#include <iostream>

int main()
{
    bool a{ true };
    bool b{ false };
    bool c{ true };

    std::cout << std::boolalpha;
    std::cout << a << '\n';
    std::cout << b << '\n';
    std::cout << c << '\n';

    std::cout << (a && b) << '\n';
    std::cout << (a || b) << '\n';
    std::cout << !c << '\n';

    return 0;
}