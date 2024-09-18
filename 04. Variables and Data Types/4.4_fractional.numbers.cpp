//
// Created by Εκλεκτός εν Χριστώ on 15/10/2023.
//

#include <iostream>
#include <iomanip>

int main()
{
    float number1{ 1.12345678901234567890F };
    double number2{ 1.12345678901234567890 };
    long double number3{ 1.12345678901234567890L };

    std::cout << sizeof(number1) << '\n';
    std::cout << sizeof(number2) << '\n';
    std::cout << sizeof(number3) << '\n';

    // setting the output precision
    std::cout << std::setprecision(20);
    std::cout << number1 << '\n';
    std::cout << number2 << '\n';
    std::cout << number3 << '\n';

    float number4{ 123456789.0F };
    double number5{ 123456789.0F };     // will be treated as float, because of prefix f
    std::cout << number4 << '\n';
    std::cout << number5 << '\n';

    // infinity and NaN
    std::cout << -2.2 / 0 << '\n';
    std::cout << 0.0 / 0.0 << '\n';

    return 0;
}