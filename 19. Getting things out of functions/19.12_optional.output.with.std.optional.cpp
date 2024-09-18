//
// Created by Εκλεκτός εν Χριστώ on 19/02/2024.
//

/*
 *
 */

#include <iostream>
#include <optional>
#include <string>

std::optional<std::size_t> find_character(const std::string& string, char c)
{
    // return index if c is found, otherwise return an empty optional
    for (std::size_t i{0}; i < string.size(); ++i)
    {
        if (string.c_str()[i] == c)
            return i;
    }

    return {};
}

// default parameter for input character, in case when char is not passed
std::optional<std::size_t> find_character_v1(const std::string& string, std::optional<char> c = std::nullopt)
{
    char char_to_find{};

    // ugly way
    if (c.has_value())
        char_to_find = c.value();
    else
        char_to_find = 'P';

    for (std::size_t i{0}; i < string.size(); ++i)
    {
        if (string.c_str()[i] == char_to_find)
            return i;
    }

    return {};
}

// better implementation of previous function
std::optional<std::size_t> find_character_v2(const std::string& string, std::optional<char> c = std::nullopt)
{
    // good way, find 'P' if c is empty
    char char_to_find{ c.value_or('P') };

    for (std::size_t i{0}; i < string.size(); ++i)
    {
        if (string.c_str()[i] == char_to_find)
            return i;
    }

    return {};
}

int main()
{
    std::string string{ "PROGRAMMING" };
    char c{ 'A' };

    auto found{ find_character(string, c) };

    if (found.has_value())
        std::cout << "Found the " << c << " at index " << found.value() << '\n';
    else
        std::cout << "Not found the " << c << '\n';

    // 2nd argument is not passed
    auto found_again{ find_character_v1(string) };

    if (found_again.has_value())
        std::cout << "Found the " << c << " at index " << found_again.value() << '\n';
    else
        std::cout << "Not found the " << c << '\n';

    return 0;
}