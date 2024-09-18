//
// Created by Εκλεκτός εν Χριστώ on 14/02/2024.
//

/*
 *
 */

#include <iostream>

// return a, return b - both are pointers, so can be returned, returned type should be
// a pointer for this
int* max(int* a, int* b)
{
    if (*a > *b)
        return a;
    else
        return b;
}

// result is local to sum - should not be returned by pointer
int* sum(int* a, int* b)
{
    int result{ *a + *b };
    return &result;
}

int* max_again(int a, int b)
{
    if (a > b)
        return &a;
    else
        return &b;
}

int main()
{
    int a{ 2 };
    int b{ 3 };

    // &a, &b - parameters are pointers, so address of a and b is required
    // ++ : data can be modified through the pointer
    std::cout << ++(*(max(&a, &b))) << '\n';

    std::cout << a << '\n';
    std::cout << b << '\n';

    a = 2;
    b = 20;

    std::cout << *(sum(&a, &b)) << '\n';

    std::cout << *(max_again(a, b)) << '\n';

    return 0;
}