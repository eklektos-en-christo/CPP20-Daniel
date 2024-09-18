//
// Created by Εκλεκτός εν Χριστώ on 6/18/24.
//

/*
 * pure virtual functions : functions that are not meant to be implemented in the base class,
 * they are declared in base but implemented in derived classes, base object creation is not
 * allowed when there are pure virtual functions in base
 *
 * syntax:      virtual function prototype = 0;     0 to make them pure virtual
 *
 * abstract class: because of pure virtual functions, the object of the class is not allowed
 * to be created, if there are one or more virtual functions, then this is an abstract class
 * but we can use base ptr to manage derived objects to use polymorphic behavior
 *
 * derived classes must override all the pure virtual functions from an abstract class, if they
 * don't, then the derived also becomes an abstract class
 *
 * abstract class's pure virtual functions can't be called in its constructor, we can use
 * the constructor of the base into derived to create base part
 */

#include <iostream>
#include "pure_virtual/Rectangle.h"
#include "pure_virtual/Circle.h"

int main()
{
    // can't create an object of an abstract class
    /*Shape* shape_ptr{ new Shape };*/

    Shape* shape_ptr{ new Rectangle{ 7, 5, "Rectangle" } };

    // polymorphic behavior
    std::cout << shape_ptr->surface() << '\n';
    std::cout << shape_ptr->perimeter() << '\n';

    std::cout << typeid(*shape_ptr).name() << '\n';

    return 0;
}