//
// Created by Εκλεκτός εν Χριστώ on 08/11/2023.
//

#include <iostream>
#include <string>

int main()
{
    // u - unsigned suffix for literal
    unsigned char u_char{ 255u };

    signed char s_char{ -128 };

    unsigned short int us_int{ 578u };

    // long literal suffix - l or L
    long l_long{ 234l };

    // long long literal suffix - LL or ll
    long long ll_long{ 234333LL };

    // grouping numbers using '
    unsigned long int ul_int{ 1'324'343'5L };
    std::cout << ul_int << '\n';

    // hexadecimal literal with prefix
    int hex{ 0xffffff };
    std::cout << hex << '\n';

    // octal literal with prefix
    int oct{ 0234 };
    std::cout << oct << '\n';

    // binary literal with prefix
    int bin{ 0b11010011100100100 };
    std::cout << bin << '\n';

    // character literal with ' '
    char literal_char{ 'a' };

    // float literal with suffix f
    float f_literal{ 23.33f };

    // a string literal with " "
    std::string s_literal{ "hi hello" };

    return 0;
}