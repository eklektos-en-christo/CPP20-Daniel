//
// Created by Εκλεκτός εν Χριστώ on 5/21/24.
//

#ifndef PRACTICE_ENGINEER_H
#define PRACTICE_ENGINEER_H

#include "Person.h"

// private inheritance
// everything from Person is private in Engineer
class Engineer : private Person
{
    friend std::ostream& operator<<(std::ostream& out, const Engineer& engineer);

public:
    Engineer() = default;
    ~Engineer() = default;

    void build_something()
    {
        // name and age are private in Engineer - so accessible
        // address is private to Engineer - inaccessible
        std::cout << m_fullname;
        std::cout << m_age;
        /*std::cout << m_address;*/
    }

    int get_contract_count() const { return contract_count; }

// declaring all of them under protected, so they are protected now in this class
// they are private when inherited from Person, their access level is changed to protected now
// the derived class can access them now
protected:
    // syntax to resurrect the base members
    using Person::get_fullname;
    using Person::get_age;
    using Person::get_address;
    // private stuff from base is not accessible, so cant change the specifer here
    /*using Person::m_address;*/
    using Person::add;

private:
    int contract_count{};
};

#endif //PRACTICE_ENGINEER_H
