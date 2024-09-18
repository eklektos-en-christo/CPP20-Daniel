//
// Created by Εκλεκτός εν Χριστώ on 5/11/24.
//

/*
 * <=> is going to be deleted by the compiler if the class has members which don't implement
 * their own <=> operator, because compiler can't compare those member variables with other
 * types
 */

#include <iostream>
#include "classes/Item.h"
#include "classes/Integer.h"

int main()
{
    Item i1{ 1,2,3 };
    Item i2{ 1,2,4 };

    std::cout << ((i1 <=> i2) != 0) << '\n';

    return 0;
}