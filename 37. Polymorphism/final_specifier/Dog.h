//
// Created by Εκλεκτός εν Χριστώ on 6/13/24.
//

#ifndef PRACTICE_DOG_H
#define PRACTICE_DOG_H

#include "Feline.h"
#include <string_view>
#include <iostream>

class Dog : public Feline
{
public:
    Dog() = default;
    Dog(std::string_view fur_style, std::string_view desc);
    virtual ~Dog() = default;

    virtual void Bark() const { std::cout << "Dog is barking" << '\n'; }

    virtual void breathe() const override
    {
        std::cout << "Dog is breathing: " << m_fur_style << '\n';
    }

    // inheriting class won't be able to override this function - marked as final
    virtual void run() const override final
    {
        std::cout << "Dog is running: " << m_fur_style << '\n';
    }
};

#endif //PRACTICE_DOG_H
