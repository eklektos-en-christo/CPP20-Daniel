//
// Created by Εκλεκτός εν Χριστώ on 6/13/24.
//

#ifndef PRACTICE_ANIMAL_H
#define PRACTICE_ANIMAL_H

#include <iostream>
#include <string>
#include <string_view>

class Animal
{
public:
    Animal() = default;
    Animal(std::string_view desc) : m_description{ desc } {}
    virtual ~Animal() { /*std::cout << "Animal Destructor called\n";*/ };

    virtual void breathe() const { std::cout << "Animal is breathing: " << m_description << '\n';}

protected:
    std::string m_description {};
};

#endif //PRACTICE_ANIMAL_H
