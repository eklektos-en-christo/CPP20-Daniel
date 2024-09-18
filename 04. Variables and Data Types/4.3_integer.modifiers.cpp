//
// Created by Εκλεκτός εν Χριστώ on 12/10/2023.
//

#include <iostream>

int main()
{
    // valid - positive/negative can be stored on signed integer
    signed int value1{ -3 };

    // invalid - unsigned can only store the positive numbers
    /*unsigned int value1{ -2 };*/

    short int value2{ 22 };
    std::cout << sizeof(value2) << '\n';

    std::cout << sizeof(int) << '\n';
    std::cout << sizeof(long int) << '\n';

    // using the integer modifier to change the size of a standard integer
    std::cout << sizeof(unsigned long long int) << '\n';

    return 0;
}
