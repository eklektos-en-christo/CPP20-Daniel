//
// Created by Εκλεκτός εν Χριστώ on 10/01/2024.
//

/*
 *
 */

#include <iostream>
#include <cstring>

int main()
{
    char dest[30]{ "hello " };
    char src[]{ "World!" };

    // concatenation
    std::strcat(dest, src);
    std::cout << dest << '\n';
    std::strcat(dest, " hello there");
    std::cout << dest <<src<< '\n';

    char dest1[30]{ "hello" };
    char src1[]{ " there again" };

    std::strncat(dest1, src1, 12);
    std::cout << dest1 << '\n';

    char dest2[30];
    char src2[]{ ", how are you?" };

    // copying
    std::strcpy(dest2, src2);
    std::cout << dest2 << '\n';

    char dest3[30];
    std::strncpy(dest3, src2, 5);
    std::cout << dest3 << '\n';

    return 0;
}