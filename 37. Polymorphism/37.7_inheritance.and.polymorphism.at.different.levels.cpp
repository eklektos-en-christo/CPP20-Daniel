//
// Created by Εκλεκτός εν Χριστώ on 6/12/24.
//

/*
 * make destructors virtual if there are virtual functions in the class
 */

#include "polymorphic_levels/Animal.h"
#include "polymorphic_levels/Feline.h"
#include "polymorphic_levels/Dog.h"
#include "polymorphic_levels/Cat.h"
#include "polymorphic_levels/Bird.h"
#include "polymorphic_levels/Pigeon.h"
#include "polymorphic_levels/Crow.h"

int main()
{
    // animal polymorphism at different level
    Dog dog1{ "Brown", "Dog1" };
    Cat cat1{ "White", "Cat1" };
    Pigeon pigeon1{ "Gray", "Pigeon1" };
    Crow crow1{ "Black", "Crow1" };

    Animal* animal_ptr[] { &dog1, &cat1, &pigeon1, &crow1 };

    for (auto& animal : animal_ptr)
    {
        animal->breathe();
    }

    // feline polymorphism at different level
    Dog dog2{ "White", "Dog2" };
    Cat cat2{ "Yellow", "Cat2" };
    Pigeon pigeon2{ "Blue", "Pigeon2" };

    Feline* feline_ptr[] { &dog2, &cat2 };

    for (auto& feline : feline_ptr)
    {
        feline->run();
    }

    // Bird polymorphism at different level, fly is not overridden in derived classes
    // so base version of fly() will be called
    Bird* bird_ptr[] { &crow1, &pigeon2 };

    for (auto& bird : bird_ptr)
        bird->fly();

    return 0;
}