//
// Created by Εκλεκτός εν Χριστώ on 15/01/2024.
//

/*
 *
 */

#include <iostream>
#include <string>

int main()
{
    std::string str1{ "HELLO" };
    std::string str2{ "WORLD" };
    const char* c_str{ "HELLO" };

    std::cout << str1.compare(str2) << '\n';
    std::cout << str2.compare(str1) << '\n';
    // compare part of c_str
    std::cout << str1.compare(0, 5, c_str) << '\n';

    return 0;
}