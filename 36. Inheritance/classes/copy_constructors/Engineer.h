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
    Engineer() = default;
    Engineer(std::string_view fullname, int age, std::string_view address, int contract_count);
    ~Engineer() = default;

    Engineer(const Engineer& src_engg);

    void build_something()
    {
        std::cout << m_fullname;
        std::cout << m_age;
    }

private:
    int contract_count{};
};

#endif //PRACTICE_ENGINEER_H
