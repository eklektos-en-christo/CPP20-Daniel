//
// Created by Εκλεκτός εν Χριστώ on 6/21/24.
//

/*
 *
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
    f1();

    return 0;
}

// multiple handles for a single exception in every function
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

    try
    {
        f3();
    }
    catch (int ex)
    {
        std::cout << "Exception handled in f2()\n";
    }

    std::cout << "Ending f2()\n";
}

void f3()
{
    std::cout << "Starting f3()\n";

    try
    {
        exception_thrower();
    }
    catch (int ex)
    {
        std::cout << "Exception handled in f3()\n";
    }

    std::cout << "Ending f3()\n";
}