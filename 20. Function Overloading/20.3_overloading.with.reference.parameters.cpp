//
// Created by Εκλεκτός εν Χριστώ on 23/02/2024.
//

/*
 * implicit conversions don't work with non const reference parameters
 * temporaries don't work with non const references
 */

#include <iostream>
#include <string>

void say_my_name(const std::string& name)
{
    std::cout << "void say_my_name(const std::string& name)" << '\n';
    std::cout << "Name is " << name << '\n';
}

void say_my_name(std::string name)
{
    std::cout << "void say_my_name(std::string name)" << '\n';
    std::cout << "Name is " << name << '\n';
}

double max(double a, double b)
{
    std::cout << "double overload called" << '\n';
    return (a > b) ? a : b;
}

// parameters are non const reference, they don't work well with implicit conversions
int& max(int& a, int& b)
{
    std::cout << "int overload called" << '\n';
    return (a > b) ? a : b;
}

int main()
{
    std::string name{ "Leon" };

    /*say_my_name(name);*/

    char a{ 22 };
    char b{ 18 };

    // a, b can be converted to int but int parameters are non const references
    // so double overload is called
    std::cout << max(a, b) << '\n';

    return 0;
}