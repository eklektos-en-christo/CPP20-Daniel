//
// Created by Εκλεκτός εν Χριστώ on 5/21/24.
//


/* base class access specifiers:
 *      derived class : public base class - "public" here is base class's access specifier
 *      it controls how accessible the base members are in the derived class
 *
 *      3 options:
 *      if we inherit publicly - anything public in base will be public in derived
 *                             anything protected in base will be protected in derived
 *                             anything private in base will be inaccessible
 *
 *      if we inherit protectedly - public in base will be protected in derived
 *                                protected in base will be protected in derived
 *                                private in base will be private inaccessible
 *
 *      if we inherit privately - public and protected in base will be private
 *                                in derived class
 *                                private in base is inaccessible in derived
 *
 * so through the base class access specifiers, we can control how relaxed or constrained
 * the access of base class members from the derived class is
 *
 * important line to remember for me : by using the specifiers, we change the specifer
 * of base class to some other specifier in derived class, this does not affect the
 * base class specifiers but in derived class, the member of base are treated with
 * as if their specifiers are changed through the type of inheritance we use to
 * inherit the base
 */

#include <iostream>
#include "classes/base_class_access_specifiers/Person.h"
#include "classes/base_class_access_specifiers/Player.h"
#include "classes/base_class_access_specifiers/Nurse.h"
#include "classes/base_class_access_specifiers/Engineer.h"

int main()
{
    Person p1{ "Daniel Licht", 38, "Toronto, Canada" };
    std::cout << p1 << '\n';

    Player player1;
    player1.play();

    std::cout << player1 << '\n';

    // public is public to the outer world also from the derived class
    player1.m_fullname = "not a fullname";

    // protected and private are inaccessible outside the derived class
    /*player1.m_age = 2;
    player1.m_address = "not an address";*/
    std::cout << player1 << '\n';

    // public & protected reamins same in derived
    // private is private always in derived
    p1.m_fullname;
    /*p1.m_age;
    p1.m_address;*/

    Nurse n1;
    n1.treat_well();
    std::cout << n1 << '\n';

    // public & protected in base are protected in derived
    // private remains inaccessible
    /*n1.m_address;
    n1.m_age;
    n1.m_fullname;*/

    Engineer e1;
    // public, protected in base are private in derived
    // private remains inaccessible
    /*e1.m_address;
    e1.m_age;
    e1.m_fullname;*/

    return 0;
}