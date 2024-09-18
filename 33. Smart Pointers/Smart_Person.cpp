//
// Created by Εκλεκτός εν Χριστώ on 4/24/24.
//

#include "Smart_Person.h"
#include <iostream>

Person::Person(std::string name) : m_name{ name }
{

}

Person::~Person()
{
    std::cout << "Person destructor called for " << m_name << '\n';
}