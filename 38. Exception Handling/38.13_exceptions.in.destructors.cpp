//
// Created by Εκλεκτός εν Χριστώ on 6/26/24.
//

/*
 * class destructor have implicitly noexcept specifier attached to them
 *
 * noexcept(false) - to allow the class destructors to propagate the exception out of
 * them, not recommended
 */

#include <iostream>

class Item
{
public:
    Item() = default;

    // by default it is noexcept, it will terminate the program if an exception goes
    // out of this destructor
    ~Item() /*noexcept(false)*/     // allow the destructor to let the exceptions propagate out of it
    {
        try
        {
            throw 1;
        }
        catch (int ex)
        {
            throw;
        }
    }
};

int main()
{
    try
    {
        // item goes out of scope after the try, this calls the destructor to cleanup
        Item item;
    }
    catch (int ex)
    {
        std::cout << "int exception handled from destructor\n";
    }

    return 0;
}