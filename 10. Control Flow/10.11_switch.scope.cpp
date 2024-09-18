//
// Created by Εκλεκτός εν Χριστώ on 16/12/2023.
//

/*
 * switch block: is a one big scope, don't declare variable inside switch cases, cases
 * may not execute where the variable is declared, if cases use {}, it creates a nested
 * scope, this will hide the variables declared in one case from another case
 */

#include <iostream>

int main()
{
    int condition{ 2 };

    switch (condition)
    {
        int x;

        case 0:
            ++x;
            break;
        case 1:
            ++x;
            break;
        case 2:
            x = 1;
            std::cout << x << '\n';
            break;

        default:
            ++x;
            std::cout << x << '\n';
    }

    return 0;
}