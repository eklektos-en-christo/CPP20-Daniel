//
// Created by Εκλεκτός εν Χριστώ on 6/15/24.
//

/*
 * destructors : are called in reverse order of constructors
 *
 * problem with polymorphic behavior when using base ptr to manage derived objects :
 * when destructors are not virtual, compiler will use the static binding to call the
 * destructors, base will be deleted when constructor is called through static binding
 *
 * virtual destructors: used to call the most derived version of the destructors when using
 * a base ptr/ref
 *
 * mark the destructors virtual when using virtual functions
 */

#include "virtual_destructors/Dog.h"

int main()
{
    // static binding - non virtual destructors
    Dog dog1;

    // managing a derived using base ptr, non virtual destructors
    Animal* p_animal{ new Dog };

    // this uses static binding to call the destructor, ptr is of type animal,
    // so animal's destructor is called - not intended
    /*delete p_animal;*/

    // when using virtual destructors - dynamic binding
    // the object is of type Dog, so dog's destructor will be called - polymorphic behavior
    // then feline and then animal
    delete p_animal;

    return 0;
}