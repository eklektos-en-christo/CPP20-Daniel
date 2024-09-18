//
// Created by Εκλεκτός εν Χριστώ on 5/13/24.
//

/*
 *
 */

#include <iostream>
#include "classes/CaseInsensitiveString.h"

int main()
{
    CaseInsensitiveString s1{ "hello" };
    CaseInsensitiveString s2{ "HELLO" };

    std::cout << std::boolalpha;
    std::cout << (s1 == s2) << '\n';
    std::cout << (s1 > s2) << '\n';
    std::cout << (s1 < s2) << '\n';

    std::cout << (s2 == "heLLO") << '\n';
    std::cout << ("HELLO" == s1) << '\n';

    return 0;
}