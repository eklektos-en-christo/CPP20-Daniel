//
// Created by Εκλεκτός εν Χριστώ on 01/01/2024.
//

/*
 *
 */

#include <iostream>
#include <cstring>

int main()
{
    const char message1[]{ "The sky is blue!" };
    const char* message2{ "The sky is blue!" };

    // strlen works both with array and decayed pointer
    std::cout << std::strlen(message1) << '\n';
    std::cout << std::strlen(message2) << '\n';
    std::cout << sizeof(message1) << '\n';
    std::cout << sizeof(message2) << '\n';

    // both are equal - 0
    std::cout << std::strcmp(message1, message2) << '\n';

    // compare first 3 characters of both strings
    std::cout << std::strncmp(message1, message2, 3) << '\n';
    std::cout << std::strncmp("hi", "ii", 2) << '\n';

    const char* str{ "programming" };
    const char* result{ str };
    char target{ 'r' };
    std::size_t iterations{};

    while ((result = std::strchr(result, target)) != nullptr)
    {
        std::cout << "Found the '" << target << "' starting at " << result << '\n';

        // pointer arithmetic - go to next character
        ++result;
        ++iterations;
    }

    std::cout << iterations << '\n';

    // find the last occurrence of '/'
    char input[]{ "/home/leon/main.cpp" };
    char* output{ std::strrchr(input, '/') };

    if (output)
        std::cout << "File name is '" << output + 1 << "'\n";

    return 0;
}