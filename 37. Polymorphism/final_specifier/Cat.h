//
// Created by Εκλεκτός εν Χριστώ on 6/13/24.
//

#ifndef PRACTICE_CAT_H
#define PRACTICE_CAT_H

#include "Feline.h"
#include <string_view>

// cat is marked as final - inheriting classes won't be able to inherit from cat
class Cat final : public Feline
{
public:
    Cat() = default;
    Cat(std::string_view fur_style, std::string_view desc);
    virtual ~Cat() = default;

    virtual void miaw() const { std::cout << "Cat is meowing: " << '\n'; }

    virtual void breathe() const override
    {
        std::cout << "Cat is breathing" << m_fur_style << '\n';
    }

    virtual void run() const override
    {
        std::cout << "Cat is running: " << m_fur_style << '\n';
    }
};

#endif //PRACTICE_CAT_H
