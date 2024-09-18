//
// Created by Εκλεκτός εν Χριστώ on 6/13/24.
//

#ifndef PRACTICE_BIRD_H
#define PRACTICE_BIRD_H

#include "Animal.h"
#include <string_view>
#include <string>

class Bird : public Animal
{
public:
    Bird() = default;
    Bird(std::string_view wing_color, std::string_view desc);
    virtual ~Bird() = default;

    virtual void fly() const { std::cout << "Bird is flying: " << m_description << '\n'; }

private:
    std::string m_wing_color {};
};

#endif //PRACTICE_BIRD_H
