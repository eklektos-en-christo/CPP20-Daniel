//
// Created by Εκλεκτός εν Χριστώ on 17/01/2024.
//

/*
 * pass by const pointer to const value : to avoid parameter modification, pointer
 * modification, copying of arguments
 */

#include <iostream>

// no copy is made of main's age, parameter is unmodifiable, pointer is also unmodifiable
void say_age(const int* const age)
{
    /*++(*age);*/
    /*age = new int{ 23 };*/
    std::cout << *age << '\n';
}

int main()
{
    int age{ 22 };
    say_age( &age );

    return 0;
}