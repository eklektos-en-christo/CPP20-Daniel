//
// Created by Εκλεκτός εν Χριστώ on 6/7/24.
//

/*
 * static binding : in compilation time, compiler decides which version of the function to be
 * called based on the type of pointer/ref is used, through a base pointer, the base version will
 * be called and if we used base pointer/ref with derived types, then also the base version of the
 * function will be called
 *
 * same methods in the base and derived: the base methods are hidden/overridden by the derived
 * methods/functions, by default
 *
 *
 */

#include <iostream>
#include "static_binding/Shape.h"
#include "static_binding/Oval.h"
#include "static_binding/Circle.h"

int main()
{
    Shape s1{ "Shape1" };
    s1.draw();

    Oval ov1{ 5, 3, "Oval1" };
    ov1.draw();

    Circle c1{ 4, "Circle1" };
    c1.draw();

    Shape* shape_ptr{ &s1 };
    shape_ptr->draw();

    // when base ptr is used with derived object
    // call to draw is determined by the type of the pointer, by default
    shape_ptr = &ov1;
    shape_ptr->draw();

    shape_ptr = &c1;
    shape_ptr->draw();

    // same happens with the base reference also
    // call to draw is determined by the type of the reference, by default
    Shape& shape_ref{ s1 };
    shape_ref.draw();

    shape_ref = ov1;
    shape_ref.draw();

    shape_ref= c1;
    shape_ref.draw();

    // collections will work only for similar elements
    Circle circle_collection[] { Circle{}, Circle{}, Circle{} };

    // different elements in a collection won't work
    /*Circle circle_collection[] { Shape{}, Oval{}, Circle{} };*/

    return 0;
}