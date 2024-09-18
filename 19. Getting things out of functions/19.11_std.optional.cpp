//
// Created by Εκλεκτός εν Χριστώ on 16/02/2024.
//

/*
 * optional - type, to handle optional output from the functions and some other things,
 * it is a wrapper type, wraps around the fundamental and other types
 *
 * they are either empty(null optional) or contain a value
 *
 * accessing an empty optional causes the crash
 *
 * to read from an optional:
 * use the value() behavior
 * or use the * operator in front of the optional name, like a pointer
 *
 * has_value() - behavior, used to check if the optional is empty or contains a value
 * std::nullopt - optional can also be checked against nullopt before accessing it
 */

#include <iostream>
#include <optional>

int main()
{
    // defining an optional, optional wrapping around an int
    std::optional<int> integer{ 2 };

    // empty initialization of an optional, initializes the string to std::nullopt
    std::optional<std::string> string{};

    // valid, instead of keeping it empty, nullopt can be used
    std::optional<double> d{ std::nullopt };

    std::cout << integer.value() << '\n';
    std::cout << *integer << '\n';

    // crash - accessing the null/empty optionals
    /*std::cout << string.value() << '\n';
    std::cout << d.value() << '\n';*/

    // perform a check before accessing the optionals
    if (d.has_value())
        std::cout << d.value() << '\n';
    else
        std::cout << "EMPTY" << '\n';

    // boolean value
    std::cout << integer.has_value() << '\n';

    // another way of checking
    if (integer == std::nullopt)
        std::cout << "EMPTY" << '\n';
    else
        std::cout << integer.value() << '\n';

    return 0;
}