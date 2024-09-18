//
// Created by Εκλεκτός εν Χριστώ on 12/01/2024.
//

/*
 * std::string.data() - returns pointer to non const
 * std::string.c_str() - returns pointer to const
 */

#include <iostream>
#include <string>

int main()
{
    std::string string { "HELLO" };

    // get the size of the string - null char is excluded
    std::cout << string.size() << '\n';

    // looping over a std::string using the size()
    for (std::size_t i{0}; i < string.size(); ++i)
        std::cout << string[i] << ' ';
    std::cout << '\n';

    // looping using a range based loop
    for (char c : string)
        std::cout << c << ' ';
    std::cout << '\n';

    // at() behavior, alternative to []
    for (std::size_t i{0}; i < string.size(); ++i)
        std::cout << string.at(i) << ' ';
    std::cout << '\n';

    // modifying single char in a std::string
    string[0] = 'B';
    string.at(1) = 'I';

    std::cout << string << '\n';

    // front and back behavior - return the copy of first and last char
    std::cout << string.front() << '\n';
    std::cout << string.back() << '\n';

    // taking the front and back by reference
    char& front{ string.front() };
    char& back{ string.back() };

    // changes are made to the original chars of string
    front = 'K';
    back = 'Z';

    std::cout << string << '\n';

    // get the underlying c string in std::string
    // c_str - returns const pointer
    const char* p_string{ string.c_str() };
    std::cout << p_string << '\n';

    // data() - returns the pointer, non-const
    char* data{ string.data() };
    data[0] = 'F';
    std::cout << data << '\n';
    std::cout << string << '\n';

    return 0;
}