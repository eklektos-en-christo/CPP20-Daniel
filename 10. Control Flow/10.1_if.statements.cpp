//
// Created by Εκλεκτός εν Χριστώ on 03/12/2023.
//

/*
 * if statement: running the code based on a true or false condition
 */

#include <iostream>

int main()
{
    int num1{ 89 };
    int num2{ 92 };

    // IF ELSE statement
    if (num1 < num2)
        std::cout << "True\n";
    else
        std::cout << "False\n";

    // nested IF statement
    if (num2 > num1)
    {
        if (num2 == num1)
            std::cout << "True\n";
        else
            std::cout << "False\n";
    }

    // combining IF statements
    if ((num2 > num1) && !(num2 == num1))
        std::cout << "True\n";

    return 0;
}