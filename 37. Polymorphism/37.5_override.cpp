//
// Created by Εκλεκτός εν Χριστώ on 6/9/24.
//

/*
 * Override : a specification, which is added to the overridden virtual functions in derived
 * classes to tell the compiler that the function is an override of base function and if the
 * base function does not match with the derived, the compiler throws an error
 *
 * syntax:
 * virtual return_type func_name() override;
 */

#include <iostream>
#include "overrides/Shape.h"
#include "overrides/Oval.h"
#include "overrides/Circle.h"

int main()
{
    Oval oval1{ 4, 3, "Shape from Oval" };

    Shape* shape_ptr{ &oval1 };

    shape_ptr->draw();

    return 0;
}