//
// Created by Εκλεκτός εν Χριστώ on 13/02/2024.
//

/*
 * input parameters can be used to take the input and output parameters in the function can
 * be used to write the output, output parameter must be a reference or a pointer
 *
 * this technique of output parameters is used to interface C++ code with C code
 */

#include <iostream>

// output is a reference - changes will be visible in the main
// const - input parameters are not meant to be changed inside
void max_int(const int x, const int y, int& output)
{
    if (x > y)
        output = x;
    else
        output = y;
}

void max_double(const double x, const double y, double* output)
{
    if (x > y)
        *output = x;
    else
        *output = y;
}

int main()
{
    int x{ 1 };
    int y{ 100 };
    int result{};
    max_int(x, y, result);
    std::cout << result << '\n';

    double a{ 2.2 };
    double b{ 2.3 };
    double double_result{};
    max_double(a, b, &double_result);
    std::cout << double_result << '\n';

    return 0;
}