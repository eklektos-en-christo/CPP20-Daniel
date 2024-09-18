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
    std::string string1{ "HELLO" };
    std::string string2{ "WORLD" };

    // concat chars and strings using operator+
    std::string message{ string1 + ' ' + string2 };
    std::cout << message << '\n';

    // error - literals are const char arrays
    /*std::cout << "hello " + "world" << '\n';*/

    // works
    std::cout << "hello " "world" << '\n';

    // turn one cstring literal into std::string
    std::cout << std::string{ "hello " } + "world" << '\n';

    // to avoid the namespace pollution in main()
    {
        using namespace std::string_literals;

        // turn one cstring literal into std::string
        std::cout << "hello "s + "world" << '\n';
    }

    std::cout << string1.append(string2) << '\n';
    std::cout << string1.append(" world") << '\n';

    string1 = "HELLO";
    string2 = "WORLD";

    // append 3 copies of '!' character
    std::cout << string1.append(3, '!') << '\n';

    // append first 4 chars of string1
    std::cout << string2.append(string1, 0, 4) << '\n';

    // both treated as integers
    std::cout << 'a' + ',' << '\n';

    // solution - add the char to an std::string
    std::cout << std::string{"hello"} + ',' << '\n';

    std::string string3{ "HELLO" };
    const char message2[]{ " WORLD" };
    const char* message3{ " WORLD" };

    // appending char arrays
    std::cout << string3.append(message2) << '\n';
    std::cout << string3.append(message3) << '\n';

    // turn int into an std::string and concatenate
    std::cout << std::string{ "hello" } + std::to_string(65) << '\n';
    std::cout << std::string{ "hello" } + std::to_string(65.1) << '\n';

    return 0;
}