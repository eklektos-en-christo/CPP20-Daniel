//
// Created by Εκλεκτός εν Χριστώ on 02/12/2023.
//

/*
 * variable's scope: region in code where a variable name can be mentioned
 * variable's lifetime: is controlled by the storage duration type of the variable
 */

#include <iostream>

// a global variable - accessible in the whole file
int g_var{ 10 };

void some_function()
{
    // local variable - visible in this function only
    int local_variable{ 72 };

    std::cout << local_variable << '\n';
    std::cout << g_var << '\n';
}

int main()
{
    some_function();

    // local variable from function not visible in the scope of main()
    /*local_variable = 73;*/

    return 0;
}