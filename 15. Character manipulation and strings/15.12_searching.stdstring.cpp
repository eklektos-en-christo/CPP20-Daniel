//
// Created by Εκλεκτός εν Χριστώ on 15/01/2024.
//

/*
 * std::string - returns a huge positive number if we don't find the string we're
 * searching for in the std::string
 */

#include <iostream>
#include <string>

int main()
{
    std::cout << std::string::npos << '\n';

    std::string string{ "The water was poured in the heater" };
    std::string search_for{ "red" };

    std::cout << "red starts at : " << string.find(search_for) << '\n';

    // when string is not found - huge number is returned, which is std::string::npos
    std::cout << string.find("hello") << '\n';

    std::size_t largest{ static_cast<size_t>(-1) };
    std::cout << largest << '\n';

    // a better handling of search result
    if (string.find("hello") == std::string::npos)
        std::cout << "hello not found\n";
    else
        std::cout << "hello found\n";

    search_for = "ter";

    // search from a specific index
    std::cout << string.find(search_for, 20) << '\n';

    const char* cstring{ "was" };

    std::cout << "was starts at : " << string.find(cstring) << '\n';

    return 0;
}