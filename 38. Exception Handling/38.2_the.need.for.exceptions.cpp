//
// Created by Εκλεκτός εν Χριστώ on 6/21/24.
//

/*
 * type of the thrown value must match with the type of the catch block, otherwise a
 * crash
 *
 * we can throw an exception from a function without try or catch block but there must
 * be a try-catch block in the caller to handle the exception
 */

#include <iostream>
#include <string>

class Animal
{
public:
    Animal() = default;
    virtual void breathe() const { std::cout << "Animal is breathing\n"; }

private:
    std::string m_description{};
};

class Dog : public Animal
{
public:
    Dog() = default;
    virtual void breathe() const override { std::cout << "Dog is breathing\n"; }
    void run() const { std::cout << "Dog is running\n"; }

private:
    std::string m_fur_color{};
};

int silent_exception()
{
    int a = 8;
    int b = 0;

    if (b == 0)
        throw "Division by 0 detected from silent_exception()\n";

    return a / b;
}

int main()
{
    const int a{ 2 };
    const int b{ 0 };

    // without exception: program crash
    /*std::cout << a / b << '\n';*/

    // no crash, exception handled
    try
    {
        if (!b)
            throw 0;

        std::cout << a / b << '\n';
    }
    catch (int ex)
    {
        std::cout << "Division by " << ex << " detected\n";
    }

    Animal animal;
    // animal has not Dog part, dynamic cast will fail and program will crash without
    // exception handling mechanism
    /*Dog& dog_ref{ dynamic_cast<Dog&>(animal) };*/

    // unhandled int exception causing the program crash
    /*silent_exception();*/

    // exception thrown by a function is handled by the caller - main()
    try
    {
        silent_exception();
    }
    catch (const char* ex)
    {
        std::cout << ex << '\n';
    }

    return 0;
}
