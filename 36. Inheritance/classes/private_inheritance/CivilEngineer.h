//
// Created by Εκλεκτός εν Χριστώ on 5/27/24.
//

#ifndef PRACTICE_CIVILENGINEER_H
#define PRACTICE_CIVILENGINEER_H

#include "Engineer.h"
#include <string>
#include <iostream>

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
    out << engineer.m_speciality;
    return out;
}

#endif //PRACTICE_CIVILENGINEER_H
