//
// Created by Εκλεκτός εν Χριστώ on 17/01/2024.
//

/*
 * pass by pointer : to modify the original data and avoid making copies of arguments
 */

#include <iostream>

void print_age(int* age)
{
    ++(*age);
    std::cout << *age << '\n';
}

int main()
{
    int age{ 22 };

    std::cout << "before call : " << age << '\n';
    print_age(&age);
    std::cout << "after call : " << age << '\n';

    return 0;
}