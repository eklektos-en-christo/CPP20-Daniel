//
// Created by Εκλεκτός εν Χριστώ on 6/13/24.
//

#ifndef PRACTICE_CROW_H
#define PRACTICE_CROW_H

#include <iostream>
#include <string_view>
#include "Bird.h"

class Crow : public Bird
{
public:
    Crow() = default;
    Crow(std::string_view wing_color, std::string_view desc);
    virtual ~Crow() = default;

    virtual void caw() const { std::cout << "Crow is cawing: " << m_description << '\n'; }
    virtual void breathe() const override { std::cout << "Crow is breathing: " << m_description << '\n';}

//    virtual void fly() const override
//    {
//        std::cout << "Crow is flying: " << m_description << '\n';
//    }
};

#endif //PRACTICE_CROW_H
