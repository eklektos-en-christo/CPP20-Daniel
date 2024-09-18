//
// Created by Εκλεκτός εν Χριστώ on 6/13/24.
//

#ifndef PRACTICE_PIGEON_H
#define PRACTICE_PIGEON_H

#include <iostream>
#include <string_view>
#include <string>
#include "Bird.h"

class Pigeon : public Bird
{
public:
    Pigeon() = default;
    Pigeon(std::string_view wing_color, std::string_view desc);
    virtual ~Pigeon() = default;

    virtual void coo() const { std::cout << "Pigeon is cooing: " << m_description << '\n'; }

    virtual void breathe() const override { std::cout << "Pigeon is breathing: " << m_description << '\n'; }

//    virtual void fly() const override
//    {
//        std::cout << "Pigeon is flying: " << m_description << '\n';
//    }
};

#endif //PRACTICE_PIGEON_H
