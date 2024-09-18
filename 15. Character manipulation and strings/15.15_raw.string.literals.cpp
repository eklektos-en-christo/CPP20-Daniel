//
// Created by Εκλεκτός εν Χριστώ on 16/01/2024.
//

/*
 * raw string literal syntax: R"(literal goes inside parentheses)"
 */

#include <iostream>
#include <string>

int main()
{
    // a raw string literal
    std::string r_literal{ R"(Programming
                                 is fun)" };
    std::cout << r_literal << '\n';

    // raw string literal works with assignments also
    std::string rsl_assign = R"(Assignment  done)";
    std::cout << rsl_assign << '\n';

    const char* cstring{ R"(this is a           cstring)" };
    std::cout << cstring << '\n';

    // problematic raw string literal - put any character(s) between " and (
    /*std::string rsl_prob{ R"("("this" pointer)")" };*/

    std::string rsl_prob{ R"===("("this" pointer)")===" };
    std::cout << rsl_prob << '\n';

    return 0;
}