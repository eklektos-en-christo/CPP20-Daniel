//
// Created by Εκλεκτός εν Χριστώ on 12/01/2024.
//

/*
 *
 */

#include <iostream>
#include <string>

int main()
{
    std::string string{ "HELLO" };

    std::cout << string.empty() << '\n';
    std::cout << string.size() << '\n';
    std::cout << string.length() << '\n';       // same as size()
    std::cout << string.max_size() << '\n';     // max size on system

    // current total chars which the string can hold without expanding itself
    std::cout << string.capacity() << '\n';

    string.reserve(50);
    std::cout << string.size() << '\n';
    std::cout << string.capacity() << '\n';

    string.shrink_to_fit();                     // shrink to fit the chars
    std::cout << string.size() << '\n';
    std::cout << string.capacity() << '\n';

    return 0;
}