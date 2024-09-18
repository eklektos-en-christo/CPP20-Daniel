//
// Created by Εκλεκτός εν Χριστώ on 6/13/24.
//

#ifndef PRACTICE_FELINE_H
#define PRACTICE_FELINE_H

#include <iostream>
#include <string_view>
#include <string>
#include "Animal.h"

class Feline : public Animal
{
public:
    Feline() = default;
    Feline(std::string_view fur_style, std::string_view desc);
    virtual ~Feline() { std::cout << "Feline Destructor called\n"; };

    virtual void run() const { std::cout << "Feline is running: " << m_fur_style << '\n'; }

    std::string m_fur_style {};
};

#endif //PRACTICE_FELINE_H
