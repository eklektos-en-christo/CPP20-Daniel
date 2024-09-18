//
// Created by Εκλεκτός εν Χριστώ on 6/25/24.
//

/*
 * when using polymorphic exceptions:
 * we can make a catch block that has a base reference and all the virtual functions will
 * be called dynamically, depending upon the type of the object is thrown from the try
 *
 * this reduces the catch block significantly
 */

#include "polymorphic_exceptions/Exceptions.h"

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
        catch (SomethingWrong& ex)
        {
            // call to what is dispatched dynamically
            // ex is base reference to the derived object, which is thrown
            // by the do_something function from try
            // polymorphic exceptions
            std::cout << "Exception: " << ex.what() << '\n';

            // checking the dynamic type referenced to by the ex
            std::cout << typeid(ex).name() << '\n';
        }
    }

    return 0;
}