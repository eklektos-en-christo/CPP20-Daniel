//
// Created by Εκλεκτός εν Χριστώ on 17/01/2024.
//

/*
 * pass by reference : to avoid making copies of the arguments and modify the original data
 */

#include <iostream>

// passing by reference
void increment(int& age)
{
    ++age;
}

int main()
{
    int age{ 2 };
    increment(age);
    std::cout << age << '\n';

    return 0;
}