//
// Created by Εκλεκτός εν Χριστώ on 5/21/24.
//

#ifndef PRACTICE_ENGINEER_H
#define PRACTICE_ENGINEER_H

#include "Person.h"
#include <string_view>

class Engineer : public Person
{
    friend std::ostream& operator<<(std::ostream& out, const Engineer& engineer);

public:

    //Engineer() = default;
    Engineer(std::string_view fullname, int age, std::string_view address, int contract_count);

    // inheriting the base constructor
    // this will generate a base like constructor in the engineer class
    // which will initialize the base portion only,
    // all person ctors will be inherited, whether default or custom
    // the actual construtor will be an engineer ctor but with base params only
    using Person::Person;

    ~Engineer() = default;

    void build_something()
    {
        std::cout << m_fullname;
        std::cout << m_age;
    }

private:
    int contract_count{};
};

#endif //PRACTICE_ENGINEER_H
