//
// Created by Εκλεκτός εν Χριστώ on 6/20/24.
//

/*
 * never throw pointers to local variables from try block, this causes undefiend behavior in
 * catch block, local variables are destroyed and pointer is left dangling
 *
 * don't throw pointer when memory is allocated in try block, this causes leakage of memory,
 * we have no way to release that dynamic memory, allocate the memory in constructor and
 * destructor will release the memory or use smart pointers
 *
 * if the exception is not handled, it crashes the program
 *
 * thrown objects must be copyable - exceptions use the object thrown in try block in the catch
 * block, so thrown type must be copyable
 */

#include <iostream>
#include <memory>

class Item
{
public:
    Item() { std::cout << "Item constructor called\n"; }
    ~Item() { std::cout << "Item destructor called\n"; }
};

class Incopyable
{
public:
    Incopyable() = default;
//    Incopyable(const Incopyable& src) = delete;

private:
    Incopyable(const Incopyable& src);
};

int main()
{
    int a{ 9 };
    int b{ 0 };

    try
    {
        Item item;                              // destroyed at try's end

        if (b == 0)
            throw b;                            // try block exits here

        std::cout << "Try block exited\n";      // never executes
    }
    catch (int exception)
    {
        std::cout << "b can't be a " << exception << '\n';
    }

    int c{ 0 };

    // don't throw pointer from try block
    try
    {
        int var{ 20 };
        int* p_var{ &var };

        if (!c)
            throw p_var;
    }
    catch (int* p_ex)
    {
        std::cout << "C can't be zero(pointer): " << *p_ex << '\n';
    }

    // p_item is leaking the memory, can't release it after the try block
    // use smart pointers
    try
    {
        Item* p_item{ new Item };

        if (c == 0)
            throw 0;
    }
    catch (int ex)
    {
        std::cout << "C can't be zero(dynamic memory)\n";
    }

    // Item is destroyed automatically because of smart pointer
    try
    {
        std::shared_ptr<Item> shared_item{ std::make_shared<Item>() };

        if (c == 0)
            throw 0;
    }
    catch (int ex)
    {
        std::cout << "C can't be zero(smart pointer): " << ex << '\n';
    }

    // an unhandled exception will crash program
    /*throw 'a';*/

    // type must be copyable to handle the exception
    /*try
    {
        Incopyable i;
        // i is not copyable to catch block's parameter i - error
        throw i;
    }
    catch (Incopyable i)
    {
        std::cout << "Class is not copyable\n";
    }*/

    return 0;
}