//
// Created by Εκλεκτός εν Χριστώ on 04/02/2024.
//

/*
 *
 */

#include <iostream>

void do_sum_print(int* ptr1, int* ptr2)
{
    std::cout << (*ptr1 + *ptr2) << '\n';
}

int main()
{
    int a{ 2 };
    int b{ 2 };

    double d1{ 2.2 };
    double d2{ 2.2 };

    do_sum_print(&a, &b);
    // double* can't be converted to an int* - this would mess up the pointer
    // arithmetic
    /*do_sum_print(&d1, &d2);*/

    return 0;
}