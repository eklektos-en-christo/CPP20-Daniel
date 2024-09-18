//
// Created by Εκλεκτός εν Χριστώ on 5/29/24.
//

/*
 * we can initialize the base class using its constructor, in the initializer list of derived
 * constructor, we can call the base constructor and pass the data which was entered to the
 * derived constructor by the user through initialization list
 */

#include <iostream>
#include "classes/custom_constructors/CivilEngineer.h"

int main()
{
    // Engineer and Person will receive their data through their custom constructors
    // civil engineer calls engineer's and engineer calls person's constructor
    CivilEngineer ce1{ "Leon", 20, "St. 42 NY 1092", 2, "Bridge Builder" };

    std::cout << ce1 << '\n';

    return 0;
}