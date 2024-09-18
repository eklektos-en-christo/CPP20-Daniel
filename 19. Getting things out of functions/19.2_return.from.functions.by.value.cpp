//
// Created by Εκλεκτός εν Χριστώ on 13/02/2024.
//

/*
 * compiler may optimize the return by value to avoid copying the return value
 */

#include <iostream>
#include <string>

// return by value - but compiler optimized it, the return string is same as the result in
// main() function
std::string concat_strings(std::string str1, std::string str2)
{
    std::string result{ str1 + str2 };
    std::cout << &result << '\n';
    return result;
}

int main()
{
    std::string str1{ "Pro" };
    std::string str2{ "gramming" };
    std::string result{ concat_strings(str1, str2) };
    std::cout << &result << '\n';
    std::cout << result << '\n';

    return 0;
}