//
// Created by Εκλεκτός εν Χριστώ on 6/15/24.
//

/*
 * default arguments: handled at compile time
 * virtual functions : are called at runtime + polymorphism
 *
 * if we use default arguments with virtual function: we might get erroneous results with
 * polymorphism
 *
 * for default arguments static binding is used to determine which arguments to pass, derived
 * or base. for polymorphism, dynamic binding is used
 *
 * compiler does not do dynamic binding with default arguments
 *
 * avoid default arguments with virtual functions
 */

#include <iostream>
#include "default_arguments/Derived.h"

int main()
{
    // when using base ref/ptr
    Base* base_ptr{ new Derived };

    // static binding is used to pass the arguments, derived default arguments are not
    // passed, the ptr is of type base, so base default arguments are passed
    std::cout << base_ptr->add() << '\n';

    Derived derived1;

    // base reference also passes the base arguments
    Base& base_ref{ derived1 };
    std::cout << base_ref.add() << '\n';

    // when using static binding - no base ref/ptr
    // object is of type base, so base args are passed
    Base base1;
    std::cout << base1.add() << '\n';

    // arguments from derived are passed, because object is of type derived
    Derived derived2;
    std::cout << derived2.add() << '\n';

    // derived part is sliced off, so base::add() is called
    // arguments from base are passed
    Base base2{ Derived{} };
    std::cout << base2.add() << '\n';

    return 0;
}