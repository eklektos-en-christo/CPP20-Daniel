//
// Created by Εκλεκτός εν Χριστώ on 6/24/24.
//

/*
 * when using hierarchical objects for exceptions:
 *
 * when using multiple catch blocks -
 * use objects in from most derived to most
 * base order, if the catch with base object is defined first, then base will catch all the
 * exceptions and we won't get specific message for each derived type of exception,
 *
 * when catches are in from most derived to most base order: if the thrown object is a derived
 * one, then specific catch block for that type will be used
 */

#include <iostream>
#include "inheritance_exceptions/Exceptions.h"

void do_something(std::size_t i)
{
    if (i == 2)
        throw CriticalError("i is 2");

    if (i == 3)
        throw SmallError("i is 3");

    if (i == 5)
        throw Warning("i is 5");

    if (i == 7)
        throw SomethingWrong("i is 7");
}

int main()
{
    for (std::size_t i{}; i < 10; ++i)
    {
        try
        {
            do_something(i);
        }
        /*
        // when base object is used first as an exception object, it catches all derived
        // exceptions, because a derived is a base also
        catch (SomethingWrong& ex)
        {
            std::cout << "SomethingWrong: " << ex.what() << '\n';
        }
        catch (Warning& ex)
        {
            std::cout << "Warning: " << ex.what() << '\n';
        }
        catch (SmallError& ex)
        {
            std::cout << "SmallError: " << ex.what() << '\n';
        }
        catch (CriticalError& ex)
        {
            std::cout << "CriticalError: " << ex.what() << '\n';
        }*/

        // specify the most derived first and most base at the end
        catch (CriticalError& ex)
        {
            std::cout << "CriticalError: " << ex.what() << '\n';
        }
        catch (SmallError& ex)
        {
            std::cout << "SmallError: " << ex.what() << '\n';
        }
        catch (Warning& ex)
        {
            std::cout << "Warning: " << ex.what() << '\n';
        }
        catch (SomethingWrong& ex)
        {
            std::cout << "SomethingWrong: " << ex.what() << '\n';
        }
    }

    return 0;
}