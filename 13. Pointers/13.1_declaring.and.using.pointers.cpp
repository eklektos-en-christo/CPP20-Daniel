//
// Created by Εκλεκτός εν Χριστώ on 22/12/2023.
//

/*
 * Pointers: special variables used to store addresses of another variables
 * pointer of an int type can store only int type addresses
 *
 * dereferencing a pointer: reading the actual value a pointer is pointing to
 */

#include <iostream>

int main()
{
    // declare a pointer to char, {} initializes it to nullptr
    char* p_ch{};

    std::cout << sizeof(p_ch) << '\n';
    std::cout << sizeof(float*) << '\n';

    int x{ 232 };

    // storing the address of x into p_int using &operator
    int* p_int{ &x };

    // prints the address of x
    std::cout << p_int << '\n';

    // accessing the address, which p_int is storing - dereferencing
    std::cout << *p_int << '\n';

    return 0;
}