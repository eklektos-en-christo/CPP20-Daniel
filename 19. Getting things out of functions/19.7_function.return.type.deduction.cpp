//
// Created by Εκλεκτός εν Χριστώ on 14/02/2024.
//

/*
 * return type can be deduced for a function by judging the return value of the
 * function
 *
 * type of all return statements must be consistent, different type will conflict
 * with each other - compiler error
 */

#include <iostream>

// auto return type deduction
auto deduce_the_return_type(int number)
{
    if (number == 0)
        return number + 1;
    else
        return number * 10;
}

int main()
{


    return 0;
}