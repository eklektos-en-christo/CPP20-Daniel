//
// Created by Εκλεκτός εν Χριστώ on 20/10/2023.
//

#include <iostream>

int main()
{
    int a{ 2 };
    int b{ 6 };
    int c{ 8 };
    int d{ 7 };
    int e{ 4 };
    int f{ 9 };
    int g{ 3 };

    // specifying to evaluate the expression inside the parentheses first - precedence
    std::cout << "Result: " << a * (e / f) + g - (b * c) / d << '\n';

    return 0;
}