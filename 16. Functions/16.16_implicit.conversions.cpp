//
// Created by Εκλεκτός εν Χριστώ on 22/01/2024.
//

/*
 *
 */

#include <iostream>

void print_sum(int a, int b)
{
    std::cout << a + b << '\n';
}

int main()
{
    print_sum(2, 2);
    print_sum(2.2, 2.2);    // implicit conversion by compiler
    print_sum(true, true);

    // function expects integers, string can't be transformed to integers
    /*print_sum("hi", "hello");*/

    return 0;
}