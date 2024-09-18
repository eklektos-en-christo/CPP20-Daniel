//
// Created by Εκλεκτός εν Χριστώ on 04/02/2024.
//

/*
 * implicit conversion from std::string_view to std::string is not allowed
 *
 * to explicit conversion when needed
 */

#include <iostream>
#include <string>
#include <string_view>

void print_std_string(const std::string& str)
{
    std::cout << str << '\n';
}

void print_string_view(std::string_view sv)
{
    // error - implicit conversion not allowed
    /*print_std_string(sv);*/

    // explicit conversion works
    print_std_string(std::string{ sv });
}

int main()
{
    print_string_view("hi");

    return 0;
}