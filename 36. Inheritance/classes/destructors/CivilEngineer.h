//
// Created by Εκλεκτός εν Χριστώ on 5/27/24.
//

#ifndef PRACTICE_CIVILENGINEER_H
#define PRACTICE_CIVILENGINEER_H

#include "Engineer.h"
#include <string>
#include <string_view>
#include <iostream>

class CivilEngineer : public Engineer
{
    friend std::ostream& operator<<(std::ostream& out, const CivilEngineer& engineer);

public:
    CivilEngineer() = default;
    CivilEngineer(std::string_view fullname, int age, std::string_view address, int count, std::string_view speciality);
    ~CivilEngineer() { std::cout << "Civil Engineer is destroyed\n"; };

    CivilEngineer(const CivilEngineer& src_civil_engg);

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
