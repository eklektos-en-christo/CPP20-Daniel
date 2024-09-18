//
// Created by Εκλεκτός εν Χριστώ on 09/11/2023.
//

/*
 * Const: it doesn't make the memory constant but makes the variable a constant, memory doesn't
 * know anything about constants
 */

#include <iostream>

int main()
{
    const int emp_id{ 2983 };

    // constant variable can't be modified once initialized
    /*emp_id = 234234;*/

    // const variable is readable
    std::cout << emp_id << '\n';

    // a const variable must be initialized
    /*const double salary;*/

    int copy_emp_id{ emp_id };
    // constant can be used in an expression
    std::cout << copy_emp_id * 2 << '\n';

    return 0;
}