//
// Created by Εκλεκτός εν Χριστώ on 24/02/2024.
//

/*
 *
 */

#include <iostream>

int max(int* a, int* b)
{
    std::cout << "(int*, int*) called\n";
    return (*a > *b) ? *a : *b;
}

int max(const int* a, const int* b)
{
    std::cout << "(const int*, const int*) called\n";
    return (*a > *b) ? *a : *b;
}

int min(const int* a, const int* b)
{
    std::cout << "(const int* const, const int* const) called\n";
    return (*a > *b) ? *a : *b;
}

// pointers are passed by value, so both upper and this function are identical
/*int min(const int* const a, const int* const b)
{
    std::cout << "(const int* const, const int* const) called\n";
    return (*a > *b) ? *a : *b;
}*/

// a reference to the main's pointer, original pointer is modified, not the copy of
// the pointer is modified
void test(int*& ptr)
{
    ++(*ptr);
}

int main()
{
    int a{ 189 };
    int b{ 192 };

    std::cout << max(&a, &b) << '\n';

    int data{ 1 };
    int* p_data{ & data };
    test(p_data);
    std::cout << data << '\n';

    return 0;
}