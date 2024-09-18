//
// Created by Εκλεκτός εν Χριστώ on 6/18/24.
//

/*
 * never call virtual functions from ctors and dtors
 *
 * if we use virtual functions in ctor - the derived part of the object will not have been created
 * when the call to a virtual function is made in a ctor and if we call a polymorphic function
 * which is living in derived part, the compiler will then call the base version of the polymorphic
 * function, because derived part isn't setup yet, we get static binding
 *
 * when calling virtual function in destructor - the derived part is deleted and when we call
 * polymorphic function, there is not virtual function, because there is not derived part alive,
 * the compiler will then call the base virtual function, we get static binding
 *
 * call the virtual functions explicitly after the construction of the full object to setup or
 * clean up and get the dynamic binding
 */

#include "virtual_functions_from_ctors_dtors/Derived.h"

int main()
{
    Base* p_base{ new Derived };

    // the derived part is not created when base part is being built,
    // static binding will cause the base setup() to be called
    std::cout << p_base->get_value() << '\n';

    // this calls the cleanup of base, derived is already deleted when
    // base is being deleted
    delete p_base;

    return 0;
}