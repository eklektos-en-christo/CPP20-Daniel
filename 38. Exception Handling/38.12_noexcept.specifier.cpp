//
// Created by Εκλεκτός εν Χριστώ on 6/25/24.
//

/*
 * noexcept - a way to tell that we don't want any exceptions propagate out of our functions
 * we can throw exception inside but they should get outside of the function unhandled, if
 * they do, the program terminates
 */

#include <iostream>

void some_function() noexcept
{
    try
    {
        throw 1;
    }
    catch (int ex)
    {
        std::cout << "int type exception handled\n";
        throw;
    }
}

class Item
{
public:
    // no exception is allowed to be propagated outside of this member
    // it it does, the terminate() is called
    void do_something() const noexcept
    {
        try
        {
            throw 2;
        }
        catch (int ex)
        {
            std::cout << "Item handling an int exception\n";
            throw;
        }
    }
};

int main()
{
    // even there is a catch block, the function is not allowed to
    // propagate any exception out of it, this still terminates the
    // program
    try
    {
        some_function();
    }
    catch (int ex)
    {
        std::cout << "int type exception handled\n";
    }

    // do_something allows exception to be propagated outside of the member
    // this calls the terminate
    Item item;
    item.do_something();

    return 0;
}