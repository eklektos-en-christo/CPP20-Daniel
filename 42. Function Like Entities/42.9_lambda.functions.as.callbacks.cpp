//
// Created by Εκλεκτός εν Χριστώ on 7/15/24.
//

/*
 * we can use lambdas as callback functions
 */

#include "lambda_callbacks/BoxContainer.h"
#include <string>

std::string& modify(std::string& input_string, char (*modifier)(const char&))
{
    for (std::size_t i{0}; i < input_string.size(); ++i)
        input_string[i] = modifier(input_string[i]);

    return input_string;
}

int main()
{
    std::string string{ "Hello World" };

    auto encrypt
    {
        [](const char& param)
        {
            return static_cast<char> (param + 8);
        }
    };

    auto decrypt
    {
        [](const char& param)
        {
            return static_cast<char> (param - 8);
        }
    };

    // using lambda functions as callbacks
    std::cout << modify(string, encrypt) << '\n';
    std::cout << modify(string, decrypt) << '\n';

    // lambda functions can alse be passed directly as callbacks
    std::cout << modify(string, [](const char& param)
    {
        return static_cast<char> (param + 8);
    }) << '\n';

    return 0;
}