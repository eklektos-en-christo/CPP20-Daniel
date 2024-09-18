//
// Created by Εκλεκτός εν Χριστώ on 6/25/24.
//

/*
 * we can rethrow an exception if we don't want to handle it, it will be handling by the
 * outer scope
 *
 * syntax: throw;
 * if throw object; is used: this will make a copy of the object and there is a danger of
 * object slicing too
 *
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
            try
            {
                do_something(i);
            }
            catch (SomethingWrong& ex_inner)
            {
                if (typeid(ex_inner) == typeid(Warning))
                    std::cout << "Inner block caught a warning: " << ex_inner.what() << '\n';
                else
                    // rethrow the same exception if the object is not a Warning
                    throw;
                    /*throw ex_inner;*/ // perfoms a copy and derived info also slices off
            }
        }
        // handles all derived types and base except Warning
        // warning is handled by inner catch
        // due to throw; at line 48, the color info is preserved
        // which means the exception object is not sliced off of its derived parts
        catch (SomethingWrong& ex_outer)
        {
            std::cout << "Outer block caught an exception: " << ex_outer.what() << '\n';
        }
    }

    return 0;
}