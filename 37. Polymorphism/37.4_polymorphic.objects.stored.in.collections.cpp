//
// Created by Εκλεκτός εν Χριστώ on 6/9/24.
//

/*
 * if we store the derived objects in an array, the derived data will be sliced off if the
 * array is of type base
 *
 * references to derived objects can't be stored in array, arrays are designed to be
 * changeable and references are not changeable to point to another data
 *
 * base pointer to derived objects can be used
 */

#include <iostream>
#include "dynamic_binding/Shape.h"
#include "dynamic_binding/Oval.h"
#include "dynamic_binding/Circle.h"
#include <memory>

int main()
{
    Circle c1{ 2, "Shape from Circle1" };
    Oval ov1{ 4, 3, "Shape from Oval1" };
    Circle c2{8, "Shape from Circle2" };
    Oval ov2{ 6, 2, "Shape from Oval2" };
    Circle c3{ 5, "Shape from Circle3" };
    Oval ov3{ 11, 10, "Shape from Oval3" };

    std::cout << sizeof(c1) << '\n';
    std::cout << sizeof(c2) << '\n';
    std::cout << sizeof(c3) << '\n';
    std::cout << sizeof(ov1) << '\n';
    std::cout << sizeof(ov2) << '\n';
    std::cout << sizeof(ov3) << '\n';

    // this stores the copies of all the derived objects into shape array
    // this array is supposed to save Shape objects but when derived objects are copied,
    // their derived part was sliced off
    Shape shape_array[] { c1, ov1, c2, ov2, c3, ov3 };

    // polymorphic behavior expected but derived objects are sliced off when copied to a
    // shape array
    for (auto& s : shape_array)
    {
        s.draw();
    }

    // slicing reduced the size of objects too
    for (auto& s : shape_array)
    {
        std::cout << sizeof(s) << '\n';
    }

    // array of references is not possible - error
    /*Shape& shape_ref_array[] { c1, ov1, c2, ov2, c3, ov3 };*/

    // array of pointers is possible and polymorphic behavior will work too
    Shape* shape_ptr_array[] { &c1, &ov1, &c2, &ov2, &c3, &ov3 };

    for (Shape* s : shape_ptr_array)
    {
        // polymorphic behavior
        s->draw();
    }

    // base ptr to derived objects using shared ptr - working
    std::shared_ptr<Shape> shared_shape[] { std::make_shared<Circle>( 5, "Circle" ), std::make_shared<Oval>( 3, 2, "Oval" ) };

    for (auto& shared : shared_shape)
    {
        shared->draw();
    }

    return 0;
}