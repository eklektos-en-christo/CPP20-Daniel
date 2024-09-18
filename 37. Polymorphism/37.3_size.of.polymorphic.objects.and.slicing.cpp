//
// Created by Εκλεκτός εν Χριστώ on 6/9/24.
//

/*
 * dynamic binding is not free: objects in dynamic binding are larger than in static one,
 *
 * Virtual table: used in dynamic binding, that keeps track of which function to call, this
 * uses space
 *
 * object slicing: when derived object is assigned to base object, the derived part is
 * stripped off and the base part of the derived is copied to the base object
 *
 */

#include <iostream>

/*
#include "dynamic_binding/Shape.h"
#include "dynamic_binding/Oval.h"
#include "dynamic_binding/Circle.h"
 */

#include "static_binding/Shape.h"
#include "static_binding/Oval.h"
#include "static_binding/Circle.h"

int main()
{
    // size in dynamic binding - 40, 56, 56 - this proves that dynamic binding used more space
    /*
    std::cout << sizeof(Shape) << '\n';
    std::cout << sizeof(Oval) << '\n';
    std::cout << sizeof(Circle) << '\n';
     */

    // size in static binding - 38, 48, 48
    std::cout << sizeof(Shape) << '\n';
    std::cout << sizeof(Oval) << '\n';
    std::cout << sizeof(Circle) << '\n';

    Circle circle{ 4, "Stuff from Circle" };

    // object slicing
    Shape shape{ circle };
    shape.draw();

    return 0;
}