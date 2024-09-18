//
// Created by Εκλεκτός εν Χριστώ on 6/2/24.
//

/*
 * by default, the base constructors are not inheritable, copy ctors are not inheritable at
 * all
 *
 * use the using syntax to inherit: the access specifier of the base
 * constructor will also be inherited, ctor will only initialize the base members and not
 * derived, regardless of the base ctor, we can also create our own derived ctor
 *
 *      using base::base_ctor;
 *
 *
 */

#include <iostream>
#include "classes/base_constructors/Person.h"
#include "classes/base_constructors/Engineer.h"

int main()
{
    // this calls the Person constructor which was generated in the Engineer
    // if the arg count is 4, then the derived ctor will be called
    // if the arg count is 3 then inherited base ctor will be called
    Engineer eng1{ "Dan Gray", 42, "Malbo, St 123, NY" };

    std::cout << eng1 << '\n';

    return 0;
}