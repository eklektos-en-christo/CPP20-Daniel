//
// Created by Εκλεκτός εν Χριστώ on 17/01/2024.
//

/*
 * pass by value : by default, the arguments are copied into the parameter variables
 */

#include <iostream>

void print_age(int age)
{
    ++age;
    std::cout << &age << " - print_age's age" << '\n';
}

int main()
{
    int age{ 23 };

    std::cout << &age << " - main's age" << '\n';
    print_age(age);                 // prints the incremented copy of main's age
    std::cout << &age << " - main's age" << '\n';       // age is unchanged by the print_age

    return 0;
}