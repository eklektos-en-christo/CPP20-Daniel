//
// Created by Εκλεκτός εν Χριστώ on 5/19/24.
//

// base class: we can use this class with derived classes

#include "Person.h"

std::ostream& operator<<(std::ostream& out, const Person& person)
{
    out << person.m_fname << ' ' << person.m_lname;
    return out;
}

Person::Person(std::string_view fname, std::string_view lname)
    : m_fname{ fname }, m_lname{ lname }
{
}