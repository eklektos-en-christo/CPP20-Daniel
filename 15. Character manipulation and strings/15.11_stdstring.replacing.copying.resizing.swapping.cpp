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
    std::string str1{ "GO TO HELL" };
    std::string str2{ "GO TO HEAVEN" };

    str1.replace(6, 4, str2, 6);
    std::cout << str1 << '\n';
    std::cout << (str1 == str2) << '\n';

    char str3[10]{};

    std::cout << std::strlen(str3) << '\n';
    str1.copy(str3, 2, 0);
    std::cout << str3 << '\n';
    std::cout << std::strlen(str3) << '\n';

    std::cout << str1 << '\n';
    str1.resize(15, '0');
    std::cout << str1 << '\n';
    std::cout << str1.size() << '\n';
    std::cout << str1.capacity() << '\n';

    str1.resize(5);
    std::cout << str1 << '\n';

    str1.swap(str2);
    std::cout << '\n' << str1 << '\n';
    std::cout << str2 << '\n';

    return 0;
}