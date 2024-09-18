//
// Created by Εκλεκτός εν Χριστώ on 6/26/24.
//

/*
 * std::exception - base class for all exception in C++
 */

#include <iostream>
#include <string>
#include <string_view>
#include <exception>

class Animal
{
public:
    Animal(std::string_view name) : m_name{ name } {}
    Animal() = default;
    virtual ~Animal() = default;
    virtual void breathe() const { std::cout << "Animal is breathing\n"; }

protected:
    std::string m_name{};
};

class Feline : public Animal
{
public:
    Feline(std::string_view name, int speed) : Animal(name), m_speed{ speed } {}

private:
    int m_speed{};
};

int main()
{
    // a base class object, has no feline info inside
    Animal animal;

    // downcasting animal to a feline reference
    // feline has no part in the animal
    // cast fails and throws an exception
    // using try to handle the exception
    try
    {
        Feline &ref_feline{dynamic_cast<Feline &>(animal)};
    }

    // exception is base reference to the thrown derived object i.e. bad_cast
    // what() is overridden function in bad_cast, it is called polymorphically
    // through base reference i.e. exception& - parameter in catch
    catch (std::exception& exception)
    {
        std::cout << "Something is wrong: " << exception.what() << '\n';
    }

    return 0;
}