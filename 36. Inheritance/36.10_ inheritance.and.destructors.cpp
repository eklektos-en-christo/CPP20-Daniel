//
// Created by Εκλεκτός εν Χριστώ on 6/6/24.
//

/*
 * destructors are called in the reverse order, from derived to base, opposite of
 * constructor calls
 */

#include <iostream>
#include "classes/destructors/Person.h"
#include "classes/destructors/Engineer.h"
#include "classes/destructors/CivilEngineer.h"

int main()
{
    // destructors are called from derived to base - reverse order
    CivilEngineer ce1;

    return 0;
}