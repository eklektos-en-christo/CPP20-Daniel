//
// Created by Εκλεκτός εν Χριστώ on 5/14/24.
//

/*
 * Inheritance : code reuse by inheriting from other classes and building relationships
 * among classes
 *
 * public inheritance : derived class can access public stuff of base class but can't
 * access the private stuff, to change the private stuff of base, we can use setters in the
 * base class
 *
 * friends of the derived class can access the private stuff of the derived class
 *
 * Derived class always have the base stuff embedded into it
 */

#include <iostream>
//#include "classes/Person.h"   // Player.h includes Person.h, so no need to include here
#include "classes/Player.h"

int main()
{
    Player p1{ "Football" };

    // Person stuff is not printed, because it is not initialized when player was initialized
    std::cout << p1 << '\n';

    // through base setters, we can set data to the private stuff of base
    // base setters are public to the derived, so accessible
    p1.set_fname("Johnny");
    p1.set_lname("Test");

    std::cout << p1 << '\n';

    return 0;
}