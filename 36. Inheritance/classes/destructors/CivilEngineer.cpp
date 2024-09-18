//
// Created by Εκλεκτός εν Χριστώ on 5/27/24.
//

#include "CivilEngineer.h"

// calling engineer's constructor, which will call Person's constructor
CivilEngineer::CivilEngineer(std::string_view fullname, int age, std::string_view address, int count, std::string_view speciality)
    : Engineer{ fullname, age, address, count }, m_speciality{ speciality }
{
    std::cout << "CivilEngineer received the data\n";
}

// src_civil_engg will be sliced off of its civil part when copied to Engineer
// and Engineer will be sliced off of its engineer part when copied to Person
CivilEngineer::CivilEngineer(const CivilEngineer& src_civil_engg)
    : Engineer(src_civil_engg), m_speciality{ src_civil_engg.m_speciality }
{
    std::cout << "Custom Copy constructor called for Civil Engg.\n";
}

void CivilEngineer::build_road()
{
    // cant access, fullname is private in engineer and private is inaccessible here
    // age is protected in person, in engineer it becomes private, which is inaccessible here
    /*std::cout << m_fullname;
    std::cout << m_age;*/
}