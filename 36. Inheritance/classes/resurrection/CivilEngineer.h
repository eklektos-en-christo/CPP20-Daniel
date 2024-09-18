//
// Created by Εκλεκτός εν Χριστώ on 5/27/24.
//

#ifndef PRACTICE_CIVILENGINEER_H
#define PRACTICE_CIVILENGINEER_H

#include "Engineer.h"
#include <string>
#include <iostream>

// it can access the public getters from Person now, Engineer has changed the access level of them
// to protected, which means they are accessible to this derived class
class CivilEngineer : public Engineer
{
    friend std::ostream& operator<<(std::ostream& out, const CivilEngineer& engineer);

public:
    CivilEngineer() = default;
    ~CivilEngineer() = default;

    void build_road();

private:
    std::string m_speciality{ "None" };
};

inline std::ostream& operator<<(std::ostream& out, const CivilEngineer& engineer)
{
    out << engineer.m_speciality << ", " << engineer.get_fullname() << ", ";
    out << engineer.get_age() << ", " << engineer.get_address();
    return out;
}

#endif //PRACTICE_CIVILENGINEER_H
