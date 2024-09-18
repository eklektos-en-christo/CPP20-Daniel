//
// Created by Εκλεκτός εν Χριστώ on 5/24/24.
//

/*
 *
 */

#include <iostream>
#include "classes/private_inheritance/Person.h"
#include "classes/private_inheritance/Engineer.h"
#include "classes/private_inheritance/CivilEngineer.h"

int main()
{
    Person p1;
    std::cout << p1 << '\n';

    Engineer e1;
    e1.build_something();

    CivilEngineer ce1;
    ce1.build_something();
    ce1.build_road();

    return 0;
}