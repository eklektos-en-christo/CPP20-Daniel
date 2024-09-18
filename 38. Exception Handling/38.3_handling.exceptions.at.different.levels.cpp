//
// Created by Εκλεκτός εν Χριστώ on 6/21/24.
//

/*
 * the further the catch block is from the throw, the bigger the damage will be,
 * exceptions can be handled anywhere in the program, they can propagate from one function to
 * another until they find the catch handler for the same exception type
 *
 * always handle the exception where it is thrown to limit the damage
 */

#include <iostream>

void f1();
void f2();
void f3();

void exception_thrower()
{
    std::cout << "Exception thrower started\n";
    throw 0;
    std::cout << "Exception thrower ended\n";
}

int main()
{
    // handling exception at different levels
    f1();

    return 0;
}

void f1()
{
    std::cout << "Starting f1()\n";
    try
    {
        f2();
    }
    catch (int ex)
    {
        std::cout << "Exception handled in f1()\n";
    }
    std::cout << "Ending f1()\n";
}

void f2()
{
    std::cout << "Starting f2()\n";
    f3();
    std::cout << "Ending f2()\n";
}

void f3()
{
    std::cout << "Starting f3()\n";
    exception_thrower();
    std::cout << "Ending f3()\n";
}