//
// Created by Εκλεκτός εν Χριστώ on 5/19/24.
//

/*
 * protected - access specifier, stuff declared under this specifier in base is accessible
 * in derived classes
 *
 * base class access specifiers:
 *      derived class : public base class - "public" here is base class's access specifier
 *      it controls how accessible the base members are in the derived class
 *
 *      3 options:
 *      if we inherit publicly - anything public in base will be public in derived
 *                               anything protected in base will be protected in derived
 *                               anything private in base will be private in derived
 *
 *      if we inherit protectedly - public in base will be protected in derived
 *                                protected in base will be protected in derived
 *                                private in base will be private in derived
 *
 *      if we inherit privately - all public private and protected in base will be private
 *                                in derived class
 *
 * so through the base class access specifiers, we can control how relaxed or constrained
 * the access of base class members from the derived class is
 */

#include <iostream>
#include "classes/protected_members/Player.h"

int main()
{
    // one param for player and other two for Person initialization
    Player p1{ "Soccer", "Lucifer", "Morningstar" };

    // Player can access the private stuff of Person and modify it
    std::cout << p1 << '\n';

    return 0;
}