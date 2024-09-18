//
// Created by Εκλεκτός εν Χριστώ on 6/18/24.
//

/*
 * typeid operator: used to check which type of object a base pointer is pointing currently,
 * works only with polymorphic types, returns the dynamic type if it finds or static if it does
 * not, if the type is not polymorphic then it returns static type/binding
 */

#include "typeid/Polymorphic.h"
#include "typeid/NonPolymorphic.h"

int main()
{
    // typeid with fundamental types
    int x{};

    std::cout << typeid(x).name() << '\n';
    std::cout << typeid(2.2).name() << '\n';

    if (typeid(int) == typeid(x))
        std::cout << "x is an int\n";
    else
        std::cout << "x is not an int\n";

    // type id with polymorphic types
    DynamicDerived dynamic;
    DynamicBase& ref_dynamic{ dynamic };

    // queries the type of object ref_dynamic is referencing - dynamic binding
    // ref is of type Base but object is derived
    std::cout << typeid(ref_dynamic).name() << '\n';

    // static binding
    std::cout << typeid(dynamic).name() << '\n';

    DynamicBase* ptr_dynamic{ &dynamic };

    // this gives the type of the pointer, not the type of the object it is pointing to - static
    std::cout << typeid(ptr_dynamic).name() << '\n';

    // gives the actual type it is pointing to - dereference is necessary to get the pointed to
    // type - dynamic binding
    std::cout << typeid(*ptr_dynamic).name() << '\n';

    // type id with non polymorphic types
    StaticDerived static_derived;
    StaticBase* ptr_static_derived{ &static_derived };
    StaticBase& ref_static_derived{ static_derived };

    // static binding - there is no virtual or polymorphism in this inheritance
    std::cout << typeid(static_derived).name() << '\n';
    std::cout << typeid(ptr_static_derived).name() << '\n';
    std::cout << typeid(ref_static_derived).name() << '\n';

    return 0;
}