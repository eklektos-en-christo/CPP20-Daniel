//
// Created by Εκλεκτός εν Χριστώ on 01/01/2024.
//

/*
 * reference can't be changed to refer to something else once declared
 * reference must be initialized
 */

#include <iostream>

int main()
{
    int data{ 9 };
    int data1{ 1000 };
    int& ref_data{ data };
    int* ptr_data{ &data };

    // ref vs pointer data
    std::cout << ref_data << '\n';
    std::cout << ptr_data << '\n';

    // ref vs pointer Write
    ref_data = 10;
    *ptr_data = 11;

    // ref vs pointer Read
    std::cout << ref_data << '\n';
    std::cout << *ptr_data << '\n';

    // this doesn't change where the reference is referencing, changes the value the reference is
    // referencing
    ref_data = data1;
    std::cout << data << '\n';

    // pointer can be changed to point somewhere else
    int data2{ 2000 };
    ptr_data = &data2;
    std::cout << *ptr_data << '\n';
    std::cout << ref_data << '\n';

    return 0;
}