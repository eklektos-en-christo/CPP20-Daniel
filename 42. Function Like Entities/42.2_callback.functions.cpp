//
// Created by Εκλεκτός εν Χριστώ on 7/13/24.
//

/*
 * callback functions: that we pass as params to other functions to be called later in the body when
 * needed
 */

#include "callback_functions/BoxContainer.h"
#include <iostream>
#include <string>

// callback functions
char encrypt(const char& c)
{
    return static_cast<char> (c + 10);
}

char decrypt(const char& c)
{
    return static_cast<char> (c - 10);
}

// passing the function through function ptr and using it inside when needed to encrypt or decrypt
std::string& modify(std::string& input_string, char (*modifier)(const char&))
{
    for (std::size_t i{0}; i < input_string.size(); ++i)
        input_string[i] = modifier(input_string[i]);

    return input_string;
}

int main()
{


    return 0;
}