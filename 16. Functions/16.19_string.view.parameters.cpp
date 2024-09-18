//
// Created by Εκλεκτός εν Χριστώ on 04/02/2024.
//

/*
 * use string_view for string input in function parameters and const references
 * for other types
 */

#include <iostream>
#include <string_view>

void say_name(std::string_view name)
{
    std::cout << "Name is " << name << '\n';
}

int main()
{
    std::string name{ "LEON" };

    say_name("LEON");
    say_name(name);
    say_name(std::string_view( name ));

    return 0;
}