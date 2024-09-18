//
// Created by Εκλεκτός εν Χριστώ on 6/8/24.
//

/*
 * late binding or
 * dynamic binding : when the member function is marked as virtual, the compiler doesn't
 * do static binding, it will not check the type of the base ptr but the type of the
 * object passed or managed by the ptr
 *
 * if the functions are not polymorphic/virtual, dynamic binding won't work, the
 * functions must be virtual in all the inheritance hierarchy for the dynmaic binding
 * to work
 */

#include "dynamic_binding/Shape.h"
#include "dynamic_binding/Oval.h"
#include "dynamic_binding/Circle.h"

void draw_shape(Shape* shape)
{
    shape->draw();
}

void draw_shape_ref(Shape& shape)
{
    shape.draw();
}

int main()
{
    Shape shape;
    Oval oval;
    Circle circle;

    Shape* shape_ptr{ &shape };
    shape_ptr->draw();

    // works as expected - the type of the object is checked at the runtime to
    // decide which function should be called
    shape_ptr = &oval;
    shape_ptr->draw();

    shape_ptr = &circle;
    shape_ptr->draw();

    Shape& shape_ref{ circle };
    shape_ref.draw();

    // works
    draw_shape(&shape);
    draw_shape(&oval);
    draw_shape(&circle);

    // works
    draw_shape_ref(shape);
    draw_shape_ref(oval);
    draw_shape_ref(circle);

    // dynamic binding won't work - function is not virtual
    /*shape_ptr->get_x_rad();*/

    // different type is a collection work because of virtual functions
    Shape* shape_collection[] { &shape, &oval, &circle };

    for (auto ptr : shape_collection)
    {
        std::cout << "LOOP: ";
        ptr->draw();
    }

    return 0;
}