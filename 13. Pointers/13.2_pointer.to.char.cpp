//
// Created by Εκλεκτός εν Χριστώ on 22/12/2023.
//

/*
 * we can initialize a pointer to a character with a string literal, make sure the
 * pointer is qualified with const keyword in from of it - const char* ptr;
 */

#include <iostream>

int main()
{
    char C[]{ "C++" };

    // first char C's address is stored in p_ch
    // p_ch points to the first character of "C++"
    char* p_ch{ C };

    std::cout << &C << '\n';
    std::cout << static_cast<void*>(p_ch) << '\n';
    std::cout << *p_ch << '\n';

    std::cout << static_cast<void*>(p_ch + 0) << '\n';
    std::cout << static_cast<void*>(p_ch + 1) << '\n';
    std::cout << static_cast<void*>(p_ch + 2) << '\n';

    return 0;
}