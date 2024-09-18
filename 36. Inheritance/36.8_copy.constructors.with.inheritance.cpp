//
// Created by Εκλεκτός εν Χριστώ on 6/1/24.
//

/*
 * when copying a class that uses inheritance and dynamic memory is being used:
 * to initialize the base part of the copy, we can pass the derived object to base constructor
 * in the initialization list of derived constructor, this will slice off the derived part and the
 * base part will be used to initialize the base class and then the derived will be initialized
 *
 * object slicing - when derived is assigned to base, the derived is sliced off and base part
 * of the derived is copied to the base
 */

#include "classes/copy_constructors/Person.h"
#include "classes/copy_constructors/Engineer.h"
#include "classes/copy_constructors/CivilEngineer.h"

int main()
{
    Engineer e1{ "Leon Dune", 24, "St. 121, NY, 10937", 3 };

    Engineer e2{ e1 };
    std::cout << e2 << '\n';

    CivilEngineer ce1{ "Leon Dune", 24, "St. 121, NY, 10937", 3, "Building Roads" };

    CivilEngineer ce2{ ce1 };
    std::cout << ce2 << '\n';

    return 0;
}