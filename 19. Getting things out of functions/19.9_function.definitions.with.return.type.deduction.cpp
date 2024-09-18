//
// Created by Εκλεκτός εν Χριστώ on 16/02/2024.
//

/*
 * with deduced return type functions, compiler has to see the full definition
 * before the function call, otherwise error, compiler needs to know the return
 * statements in the function definition, the solution is to put the definition
 * before the function call, before the main()
 */

#include <iostream>

// declaration
auto& max(int& a, int& b);

// definition
auto& max(int& a, int& b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main()
{
    int a{ 99 };
    int b{ 2 };

    int& result{ max(a, b) };

    return 0;
}

