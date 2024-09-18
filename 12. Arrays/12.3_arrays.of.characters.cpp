//
// Created by Εκλεκτός εν Χριστώ on 19/12/2023.
//

/*
 * char arrays: collection of characters
 *
 * null terminator: appended at the end of the char array to indicate the end of the string,
 * these are called null terminated strings or C-style strings
 *
 * string literal in char array : null terminator is appended automatically
 *
 * arrays other than char arrays can't be printed directly using std::cout
 */

#include <iostream>

int main()
{
    char message[]{ 'h', 'e', 'l', 'l', 'o' };

    for (auto c : message)
        std::cout << c << ' ';
    std::cout << '\n';

    std::cout << message << '\n';

    // remaining one element if filled with 0
    char message1[6] { 'J', 'e', 'l', 'l', 'o' };
    std::cout << message1 << '\n';

    // a string literal used with char array
    char my_string[]{ "This is a string literal" };
    std::cout << my_string << '\n';

    return 0;
}