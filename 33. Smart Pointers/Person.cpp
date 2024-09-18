//
// Created by Εκλεκτός εν Χριστώ on 4/20/24.
//

#include <iostream>
#include "Person.h"
#include "Dog.h"

Person::Person(std::string name) : m_name{ name }
{

}

void Person::adopt_dog(std::unique_ptr<Dog> dog)
{
    std::cout << m_name << " adopted the dog " << dog->get_name() << '\n';
}