//
// Created by Εκλεκτός εν Χριστώ on 13/02/2024.
//

/*
 * don't return references to local variables from the functions
 */

#include <iostream>

int& max(int& a, int& b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main()
{
    int a{ 11 };
    int b{ 2 };

    int& max_result{ max(a, b) };

    std::cout << ++max_result << '\n';

    return 0;
}