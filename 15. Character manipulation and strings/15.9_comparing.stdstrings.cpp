//
// Created by Εκλεκτός εν Χριστώ on 13/01/2024.
//

/*
 *
 */

#include <iostream>
#include <string>

int main()
{
    std::string str1{ "HELLO" };
    std::string str2{ "BELLO" };

    std::cout << std::boolalpha;
    std::cout << (str1 == str2) << '\n';
    std::cout << (str1 != str2) << '\n';
    std::cout << (str1 > str2) << '\n';
    std::cout << (str1 < str2) << '\n';

    const char* cstring{ "HELLO" };

    std::cout << (str1 == cstring) << '\n';
    std::cout << str1.size() << '\n';
    std::cout << std::strlen(cstring) << '\n';

    // bad
    const char cstring_nonull[]{ 'H', 'E', 'L', 'L', 'O' };

    std::cout << (str1 == cstring_nonull) << '\n';
    std::cout << (str1 > cstring_nonull) << '\n';
    std::cout << std::strlen(cstring_nonull) << '\n';


    return 0;
}