//
// Created by Εκλεκτός εν Χριστώ on 16/02/2024.
//

/*
 * two ways to return an optional output from functions:
 * - use an output parameter in the function
 * - use an error code/return type
 */

#include <iostream>
#include <string>

int find_char_v0(const std::string& string, char c)
{
    int not_found{ -1 };

    // if found, return the index i, otherwise return the error code -1
    for (std::size_t i{0}; i < string.size(); ++i)
    {
        if (string.c_str()[i] == c)
            return i;
    }

    return not_found;
}

// using an output parameter
void find_char_v1(const std::string& string, char c, bool& success)
{
    for (std::size_t i{0}; i < string.size(); ++i)
    {
        if (string.c_str()[i] == c)
        {
            success = true;
            return;
        }
    }

    success = false;
}

int main()
{
    std::string string{ "Hello C++" };
    char c{ 'C' };

    auto found_v0{ find_char_v0(string, c) };

    if (found_v0 == -1)
        std::cout << "Not found\n";
    else
        std::cout << "Found at index " << find_char_v0(string, c) << '\n';

    char c1{ 'K' };
    bool success{ false };

    find_char_v1(string, c1, success);

    if (success)
        std::cout << "Found\n";
    else
        std::cout << "Not found\n";

    return 0;
}