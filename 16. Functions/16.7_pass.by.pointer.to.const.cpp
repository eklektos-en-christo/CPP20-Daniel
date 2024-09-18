//
// Created by Εκλεκτός εν Χριστώ on 17/01/2024.
//

/*
 * pass by pointer to const : to avoid making copies of arguments and prevent the parameters
 * from being modified by the function
 */

#include <iostream>

// no copy is made of main's age, parameter is unmodifiable
void say_age(const int* age)
{
    /*++(*age);*/
    std::cout << *age << '\n';
}

int main()
{
    int age{ 22 };
    say_age( &age );

    return 0;
}