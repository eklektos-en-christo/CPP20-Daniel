//
// Created by Εκλεκτός εν Χριστώ on 5/27/24.
//

#include "CivilEngineer.h"

void CivilEngineer::build_road()
{
    // cant access, fullname is private in engineer and private is inaccessible here
    // age is protected in person, in engineer it becomes private, which is inaccessible here
    /*std::cout << m_fullname;
    std::cout << m_age;*/

    // they are private in engineer but engineer has changed their access level to protected,
    // so they are accessible here
    std::cout << add(2, 2) << '\n';
    std::cout << add(2, 2, 2) << '\n';
}