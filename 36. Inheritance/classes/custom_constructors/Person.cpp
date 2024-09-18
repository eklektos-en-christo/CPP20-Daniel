//
// Created by Εκλεκτός εν Χριστώ on 5/19/24.
//

// base class: we can use this class with derived classes

#include "Person.h"

std::ostream& operator<<(std::ostream& out, const Person& person)
{
    out << person.m_fullname << ' ' << person.m_age << ", " << person.m_address;
    return out;
}

Person::Person(std::string_view full_name, int age, std::string_view address)
    : m_fullname{ full_name }, m_age{ age }, m_address{ address }
{
    std::cout << "Person received the data\n";
}