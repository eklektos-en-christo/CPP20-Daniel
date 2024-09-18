//
// Created by Εκλεκτός εν Χριστώ on 6/11/24.
//

/*
 * overriding : a way to ecllipse the same virtual functions in a base class from the derived class
 *
 * if we have overloads of a virtual function in base class and derived class overrides any one
 * the overloads from the base, then  all the overloads in the base will be overridden by the
 * derived overrides
 */

#include <iostream>
#include "overloading_overriding_hiding/Shape.h"
#include "overloading_overriding_hiding/Oval.h"
#include "overloading_overriding_hiding/Circle.h"

int main()
{
    Circle circle1{ 5, "Shape from circle1" };
    Oval oval1{ 4, 3, "Shape from oval1" };

    // shape::draw and shape::draw(int) are available in derived classes, because
    // no other virtual function is overriding them in the derived classes
    /*circle1.draw();
    circle1.draw(2);*/

    // if some function is overriding the base overloaded functions,
    // then the overloads in the base won't be accessible in derived classes
    /*circle1.draw(2);*/

    // Oval has the overridden function draw which is accessible in circle
    // but oval has overridden the overloads which are in shape(base)
    // only the oval's overridden function is accessible now
    // base overloads are eclipsed/hidden by the oval's override
    circle1.draw();
//    circle1.draw(2);

    Shape* shape_ptr{ &oval1 };

    // this won't work, because base doesn't have this function, oval overrides it but
    // base doesn't have it, no polymorphism
    //shape_ptr->draw(3, "Red");

    return 0;
}