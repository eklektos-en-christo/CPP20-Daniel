//
// Created by Εκλεκτός εν Χριστώ on 16/01/2024.
//

/*
 * don't use non-null terminated strings with std::string_view
 *
 * string_view - can be initialized with std::string, cstring, char array, non-null
 * terminated string
 *
 * non-null terminated strings' size should be passed when initializing the string
 * view
 *
 * string view shouldn't outlive the string it is viewing
 *
 * string view behaviors - length, front, back, substr etc.
 */

#include <iostream>
#include <string_view>

int main()
{
    std::string_view sv{ "PROGRAMMING" };
    std::string_view sv1{ sv };     // no copy
    std::string_view sv2{ sv };     // no copy

    std::cout << sizeof(std::string_view) << '\n';

    char c_array[]{ 'a', 'b', 'c' };
    // size required when initializing with non-null terminated string
    std::string_view sv3{ c_array, 3 };
    std::cout << sv3 << '\n';

    std::string string{ "C++ PROGRAMMING" };
    std::string_view sv4{ string };

    string = "CPP PROGRAMMING";

    // changes reflected in string_view
    std::cout << sv4 << '\n';

    // shrink the viewing window, this doesn't affect the original string
    sv4.remove_prefix(4);
    sv4.remove_suffix(4);

    std::cout << sv4 << '\n';

    std::string_view sv5;
    {
        std::string string_scoped{ "STRING" };
        sv5 = string_scoped;
        std::cout << sv5 << '\n';
    }

    // string_scoped is destroyed already
    /*std::cout << sv5 << '\n';*/

    sv5 = string;

    // string view supports data behavior
    auto* c_ptr{ sv5.data() };
    std::cout << std::strlen(c_ptr) << '\n';

    sv5.remove_prefix(4);
    sv5.remove_suffix(4);

    c_ptr = sv5.data();

    // not working well with modified view
    std::cout << std::strlen(c_ptr) << '\n';
    std::cout << sv5.size() << '\n';

    return 0;
}