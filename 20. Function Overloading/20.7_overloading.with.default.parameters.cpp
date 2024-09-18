//
// Created by Εκλεκτός εν Χριστώ on 25/02/2024.
//

/*
 *
 */

#include <iostream>

void print_age(int age = 2)
{
    std::cout << age << '\n';
}
void print_age(long int age = 3)
{
    std::cout << age << '\n';
}

int main()
{
    // both print_age are same, types are different but values are both int
    /*print_age();*/

    return 0;
}