//
// Created by Εκλεκτός εν Χριστώ on 5/29/24.
//

/*  RESURRECTION:
 * in private inheritance - everything is not accessible to the derived class, to allow the access
 * to derived class, we can change the access level by using the using keyword
 *
 * first choose the access specifier under which we need to declare the member
 *
 *  e.g.        protected:
 *                      using base::member1;
 *                      using base::member2;
 *
 * base members declared using the using keyword under protected access specifer, this makes the
 * both members protected now
 *
 * but private base member can't be changed in the derived to become public or protected, they
 * remain inaccessible in derived
 *
 * in case of function we only use function name to resurrect and not function with ()
 * if base has overloads, they can also be resurrected in derived which inherits the base privately
 * so that the downstream classes may use them
 */

#include <iostream>
#include "classes/resurrection/Person.h"
#include "classes/resurrection/Engineer.h"
#include "classes/resurrection/CivilEngineer.h"

int main()
{
    Engineer e1;
    CivilEngineer ce1;

    std::cout << e1 << '\n';
    std::cout << ce1 << '\n';
    ce1.build_road();

    return 0;
}