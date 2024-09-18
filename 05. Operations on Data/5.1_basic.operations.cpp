//
// Created by Εκλεκτός εν Χριστώ on 16/10/2023.
//

#include <iostream>

int main()
{
    // addition
    int num1 {3};
    int num2 {4};
    int result1 { num1 + num2 };
    std::cout << "Addition: " << result1 << '\n';

    // subtraction
    int num3 {5};
    int num4 { 1 };
    int result2 { num3 - num4};
    std::cout << "Subtraction: " << result2 << '\n';

    // multiplication
    int num5 {10};
    int num6 {7};
    int result3 { num5 * num6 };
    std::cout << "Multiplication: " << result3 << '\n';

    // division - gives quotient
    int num7 {207};
    int num8 {2};
    int result4 { num7 / num8 };
    std::cout << "Division: " << result4 << '\n';

    // modulus - gives remainder
    int num9 {301};
    int num10 {3};
    int result5 { num9 % num10 };
    std::cout << "Modulus: " << result5 << '\n';

    return 0;
}