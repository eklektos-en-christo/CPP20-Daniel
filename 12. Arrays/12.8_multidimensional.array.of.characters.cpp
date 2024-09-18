//
// Created by Εκλεκτός εν Χριστώ on 21/12/2023.
//

/*
 * we can create multidimensional char arrays by using string literals
 */

#include <iostream>

int main()
{
    char abc[2][26];
    int A{65};
    int a{97};

    for (std::size_t i{0}; i < 1; ++i)
    {
        for (std::size_t j{0}; j < 26; ++j)
        {
            abc[i][j] = static_cast<char>(A);
            ++A;
        }
    }

    for (std::size_t i{1}; i < 2; ++i)
    {
        for (std::size_t j{0}; j < 26; ++j)
        {
            abc[i][j] = static_cast<char>(a);
            ++a;
        }
    }

    for (std::size_t i{0}; i < 2; ++i)
    {
        for (std::size_t j{0}; j < 26; ++j)
        {
            std::cout << abc[i][j] << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}