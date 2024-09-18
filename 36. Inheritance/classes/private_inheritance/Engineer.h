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

private:
    int contract_count{};
};

#endif //PRACTICE_ENGINEER_H
