//
// Created by Εκλεκτός εν Χριστώ on 02/02/2024.
//

/*
 *
 */

#include <iostream>

void increment(int& value)
{
    ++value;
    std::cout << "Value is : " << value << '\n';
}

void print(const int& value)
{
    std::cout << "Value is : " << value << '\n';
}

int main()
{
    int int_var{ 2024 };

    increment(int_var);
    print(int_var);

    double d_var{ 20.24 };

    // compiler is confused whether the d_var will be modified or temporary
    // variable(casted one from double to int) will be modified - error
    /*increment(d_var);*/
    print(d_var);

    return 0;
}