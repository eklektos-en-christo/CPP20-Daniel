//
// Created by Εκλεκτός εν Χριστώ on 25/02/2024.
//

/*
 * lambda functions : mechanism to set up anonymous functions(without names)
 * they can be used directly or we can give them a name to use them multiple times
 * afterwards.
 *
 * signature:
 *             [capture list](parameters) -> return type
 *             {
 *             function body
 *             };
 * lambda expression can be used in a print statement
 */

#include <iostream>

int main()
{
    // lambda function without a name
    []()
    {
        std::cout << "Hello\n";
    };

    // lambda function without name, called instantly without name
    []()
    {
        std::cout << "Hello\n";
    }();    // calling using (), no arguments needed, because no parameters

    // parameter list is not needed when parameters are not passed
    auto print_hello{ []{ std::cout << "HELLO\n"; } };

    // calling a named lambda function
    print_hello();

    // with parameters, arguments passed at the direct call 2, 10
    [](int a, int b)
    {
        std::cout << a + b << '\n';
    }(2, 10);

    // return value from lambda stored in double_sum then called with arguments
    auto double_sum{ [](double a, double b){ return a + b; } };

    std::cout << double_sum(2.1, 2.2) << '\n';
    std::cout << double_sum(3.2, 4.8) << '\n';

    // lambda expression in a print statement
    std::cout << [](double a, double b){ return a + b; }(22, 1) << '\n';

    // explicitly specifying the return type of the lambda, implicit conversion from double to
    // int type
    auto forced_int{ [](double a, double b) -> int { return a + b; } };
    std::cout << forced_int(2.2, 2.2) << '\n';
    std::cout << sizeof(forced_int(2.2, 2.2)) << '\n';

    return 0;
}