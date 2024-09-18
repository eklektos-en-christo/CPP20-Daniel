//
// Created by Εκλεκτός εν Χριστώ on 6/18/24.
//

/*
 * dynamic casting - used to do downstream casting between the polymorphic types, from base
 * to derive cast
 *
 * dynamic cast only works with polymorphic hierarchy
 *
 * we can convert a base ptr to derived ptr
 * we can also convert a base ref to derived ptr
 * we can also convert a base ref to derived ref
 *
 * when we use a base ptr - we can only call the virtual functions in the derived classes,
 * if we convert the base ptr to the specific derived type, we can call all other functions
 * from that type using the ptr of that class/type
 *
 * dynamic_cast<output_type>(input_type)
 *
 * with references, we can't check if the dynamic cast has succeeded, with pointers, we can
 *
 * dynamic casts are useful when using standalone functions to cast the base to downstream
 * class
 */

#include "dynamic_casting/Dog.h"

Feline* animal_to_feline(Animal* p_animal)
{
    return dynamic_cast<Feline*>(p_animal);
}

Feline& animal_to_feline_ref(Animal& ref_animal)
{
    return dynamic_cast<Feline&>(ref_animal);
}

int main()
{
    // base ptr managing a derived object
    Animal* p_animal{ new Feline };

    // base ptr can't access a derived non virtual function
    /*p_animal->do_feline_thing();*/

    // downcasting base* to derived* using dynamic_cast and storing it in a derived*
    Feline* p_feline{ dynamic_cast<Feline*>(p_animal) };

    // derived* can access its own non-virtual functions now
    p_feline->do_feline_thing();

    // base ptr to derived type which is not part of the object - failed dynamic cast
    // undefined behavior
    Dog* p_dog{ dynamic_cast<Dog*>(p_animal) };
    /*p_dog->dog_speed();*/

    // doing a check to see if the dynamic cast has succeeded - safe code
    if (p_dog)
        p_dog->dog_speed();
    else
        std::cout << "Animal to Dog cast has failed\n";

    // base ref to a derived object
    Feline feline1;
    Animal& ref_animal{ feline1 };

    // base ref can't access non virtual function of derived
    /*ref_animal.do_feline_thing();*/

    // downcasting the base ref to a derived ref to access the non virtual derived functions
    Feline& ref_feline{ dynamic_cast<Feline&>(ref_animal) };
    ref_feline.do_feline_thing();

    // base ref to a derived ptr, address is need to store in the derived ptr, so &ref_animal
    Feline* p_feline2{ dynamic_cast<Feline*>(&ref_animal) };

    if (p_feline2)
        p_feline2->do_feline_thing();
    else
        std::cout << "Can't cast from base ref to a derived ptr\n";

    Animal* p_animal2{ new Feline };

    // using a standalone function to cast from base to derived ptr
    animal_to_feline(p_animal2)->do_feline_thing();

    // function with base ref to derived ref conversion
    animal_to_feline_ref(ref_animal).do_feline_thing();

    return 0;
}