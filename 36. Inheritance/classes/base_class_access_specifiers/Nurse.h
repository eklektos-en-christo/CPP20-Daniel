//
// Created by Εκλεκτός εν Χριστώ on 5/21/24.
//

#ifndef PRACTICE_NURSE_H
#define PRACTICE_NURSE_H

#include "Person.h"

// protected inheritance - private in Person is private in Nurse
// public and protected in Person are protected in Nurse
class Nurse : protected Person
{
    friend std::ostream& operator<<(std::ostream& out, const Nurse& nurse);

public:
    Nurse() = default;
    ~Nurse() = default;

    void treat_well()
    {
        m_fullname = "treated";

        // fullname and age are protected in Nurse - protected inheritance
        std::cout << m_fullname << ", " << (m_age = 32)<< ", " << (cert_id = 2353);

        // private from Person is private in nurse too
        /*m_address = "dfdfd";*/
    }

private:
    int cert_id{};
};

#endif //PRACTICE_NURSE_H
