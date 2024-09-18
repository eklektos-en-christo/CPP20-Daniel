//
// Created by Εκλεκτός εν Χριστώ on 28/02/2024.
//

/*
 * sometimes it is hard to track the return type of the lambda if there are multiple
 * different types of parameters passed to the lambda function, we can use template
 * parameters to solve this, template parameters are passed between [] and () in <>
 * brackets
 */

#include <iostream>

int main()
{
    auto add
    {
        // enforcing to use only one type for both parameters in the call
        // we can also use multiple parameters typename T, typename P etc.
        []<typename T>(T a, T b)
        {
            return a + b;
        }
    };

    int a{ 22 };
    double b{ 3.98 };

    // compiler will generate a template instance for the lambda function
    // int and double passed - error, only one type can be used
    /*auto result{ add(a, b) };*/

    // working now - both 2 and 2 are ints
    auto result{ add(2, 2) };

    std::cout << result << '\n';

    return 0;
}