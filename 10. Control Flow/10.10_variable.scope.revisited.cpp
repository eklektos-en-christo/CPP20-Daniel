//
// Created by Εκλεκτός εν Χριστώ on 16/12/2023.
//

/*
 * variable initialized in if block is not accessible in else block
 * variable initialized in else block is only accessible in else block
 */

#include <iostream>

int main()
{
    if (0)
    {
        // if_var is accessible only in this IF block, not in the ELSE also
        int if_var{ 1 };
    }
    else
    {
        // std::cout << if_var << '\n';
    }

    return 0;
}