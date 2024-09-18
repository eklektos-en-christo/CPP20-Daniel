//
// Created by Εκλεκτός εν Χριστώ on 4/19/24.
//

/*
 * smart pointers : live in <memory> header
 * dynamic memory management is easier with smart pointers
 *
 * unique pointers : at any given time only one pointer manages the memory, memory is released
 * automatically when the pointer goes out of scope
 *
 * with raw pointers, we have to delete explicitly the heap memory, but with smart pointers
 * we don't need to de-allocate the memory, it is deleted automatically by the smart
 * pointers internally
 *
 * unique pointers - don't allow copies to be made
 *
 */

#include <iostream>
#include <memory>       // for unique pointer
#include "Dog.h"

int main()
{
    // stack variables are managed automatically
    /*Dog dog1{ "Lola" };
    dog1.print_dog();*/

    Dog* dog2{ new Dog{ "Gola" } };

    // managing a previously allocated memory - possible with smart pointers
    std::unique_ptr<Dog> up_dog1{ dog2 };
    up_dog1->print_dog();

    // explicitly initializing the Dog using new
    std::unique_ptr<Dog> up_dog2{ new Dog{ "Bola" } };
    up_dog2->print_dog();
    up_dog2->set_name("Pola");
    up_dog2->print_dog();

    // raw pointer managed by the up_dog2 unique_ptr
    // get returns raw pointer, * derefrences that pointer
    // which gives the object, . operator used to access get_name
    std::cout << (*(up_dog2.get())).get_name() << '\n';

    // we can avoid using new operator and use make_unique to handle the memory allocation
    std::unique_ptr<Dog> up_dog3{ std::make_unique<Dog>("Zulu") };
    up_dog3->print_dog();
    up_dog3->set_name("Yulu");
    up_dog3->print_dog();
    std::cout << (*(up_dog3.get())).get_name() << '\n';

    std::unique_ptr<Dog> a_dog = std::make_unique<Dog>("test");

    // copy not allowed - deleted copy constructor
    /*std::unique_ptr<Dog> another_dog = a_dog;*/

    // moving is allowed
    std::unique_ptr<Dog> move_the_dog{ std::move(a_dog) };
    move_the_dog->set_name("Dog is moved");
    move_the_dog->print_dog();

    // moved ptr is null now
    std::cout << a_dog << '\n';

    // we can also reset the unique pointer
    move_the_dog.reset();
    std::cout << move_the_dog << '\n';      // reset, null now

    return 0;
}