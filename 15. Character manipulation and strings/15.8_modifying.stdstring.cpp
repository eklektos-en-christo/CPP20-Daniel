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
    std::string string{ "clear this string" };
    std::cout << string << '\n';
    string.clear();
    std::cout << string << '\n';
    std::cout << string.size() << '\n';
    std::cout << string.capacity() << '\n';

    string = "HELLO";

    string.insert(5, 8, 'W');
    std::cout << string << '\n';

    const char* cstring{ " WORLD" };
    string.insert(13, cstring);
    std::cout << string << '\n';

    string.insert(19, cstring, 3);
    std::cout << string << '\n';

    string = "HELLO";

    std::string another_string{ " WORLD" };
    string.insert(5, another_string);
    std::cout << string << '\n';

    string.insert(11, another_string, 2, 2);
    std::cout << string << '\n';
    string.append("!");

    string.erase(11, 2);
    std::cout << string << '\n';

    string.push_back('!');
    string.push_back('!');
    std::cout << string << '\n';

    string.pop_back();
    string.pop_back();
    string.pop_back();
    std::cout << string << '\n';

    return 0;
}