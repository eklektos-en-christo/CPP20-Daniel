//
// Created by Εκλεκτός εν Χριστώ on 01/01/2024.
//

/*
 *
 */

#include <iostream>

int main()
{
    char c[]{ "hEllo 123 wOrld  hi" };

    // check for alphabets and numbers
    for (auto& ch : c)
    {
        if (std::isalnum(ch))
            std::cout << ch << " is alphanumeric.\n";
        else
            std::cout << ch << " isn't alphanumeric.\n";
    }

    std::cout << '\n';

    // check for alphabets
    for (auto& ch : c)
    {
        if (std::isalpha(ch))
            std::cout << ch << " is alphanumeric.\n";
        else
            std::cout << ch << " isn't alphanumeric.\n";
    }

    std::cout << '\n';

    // check for blank characters
    std::size_t blank_count{ 0 };
    for (auto& ch : c)
    {
        if (std::isblank(ch))
        {
            std::cout << ch << " is blank.\n";
            ++blank_count;
        }
        else
            std::cout << ch << " isn't blank.\n";
    }
    std::cout << "Total blanks : " << blank_count << '\n';

    std::cout << '\n';

    // check for uppercase and lowercase
    for (auto& ch : c)
    {
        if (std::isupper(ch))
            std::cout << ch << " is uppercase.\n";
        else if (std::islower(ch))
            std::cout << ch << " is lowercase.\n";
        else
            std::cout << ch << " isn't uppercase.\n";
    }

    std::cout << '\n';

    for (auto& ch : c)
    {
        if (std::isdigit(ch))
            std::cout << ch << " is a digit.\n";
        else
            std::cout << ch << " isn't a digit.\n";
    }

    std::cout << '\n';

    // changing to uppercase
    std::cout << c << '\n';
    for (auto& ch : c)
    {
        if (std::isupper(ch) || std::islower(ch))
        {
            ch = std::toupper(ch);
        }
    }
    std::cout << c << '\n' << '\n';

    return 0;
}