//
// Created by Εκλεκτός εν Χριστώ on 19/01/2024.
//

/*
 * const reference passing - to avoid making copies and modifying the original data
 */

#include <iostream>

// passing by const reference
void increment(const int& age)
{
    /*++age;*/  //read only
    std::cout << age << '\n';
}

int main()
{
    int age{ 2 };
    increment(2);
    std::cout << age << '\n';

    return 0;
}