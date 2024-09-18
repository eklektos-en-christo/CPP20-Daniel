//
// Created by Εκλεκτός εν Χριστώ on 17/01/2024.
//

/*
 * to prevent the function from altering the parameter value, we can make it const
 */

#include <iostream>

void inc_age(const int age)
{
    /*++age;*/
}

int main()
{
    int age{ 23 };

    inc_age(age);

    return 0;
}