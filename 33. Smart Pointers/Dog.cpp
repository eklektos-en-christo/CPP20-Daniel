//
// Created by Εκλεκτός εν Χριστώ on 4/19/24.
//

#include "Dog.h"
#include <iostream>

Dog::Dog(std::string name) : m_name{ name }
{
}

Dog::~Dog()
{
    std::cout << "Dog destructor called for : " << m_name << '\n';
}