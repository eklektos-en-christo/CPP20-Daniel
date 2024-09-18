//
// Created by Εκλεκτός εν Χριστώ on 5/13/24.
//

/*
 *
 */

#include <iostream>
#include "classes/ComparableString.h"
#include <string>

int main()
{
    ComparableString s1{ "FOG" };
    ComparableString s2{ "DOG" };

    std::cout << std::boolalpha;
    std::cout << (s1 == s2) << '\n';    // equal in size but not absolute equality
    std::cout << (s1 < s2) << '\n';
    std::cout << (s1 > s2) << '\n';

    return 0;
}