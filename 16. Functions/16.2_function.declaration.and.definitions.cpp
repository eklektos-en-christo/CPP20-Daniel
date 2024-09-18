//
// Created by Εκλεκτός εν Χριστώ on 17/01/2024.
//

/*
 * signature - doesn't include return type
 * prototype - headers the return type
 */

#include <iostream>

// declaration/prototype only - parameter names can be omitted in function declarations
int max(int, int);

int main()
{
    std::cout << max(2, 3) << '\n';

    return 0;
}

// function definition
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}