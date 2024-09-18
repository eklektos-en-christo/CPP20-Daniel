//
// Created by Εκλεκτός εν Χριστώ on 6/15/24.
//

/*
 * if we use non-virtual functions in base and derived - then static binding rules will
 * apply
 *
 */

#include "non_polymorphic_funcs_and_specifiers/Ellipse.h"
#include <memory>

int main()
{
    std::shared_ptr<Shape> shape_ptr{ std::make_shared<Ellipse>(4, 2, "Ellipse1") };

    // static binding, base ptr - no polymorphism, no virtual functions
    shape_ptr->draw();

    // func is private in base
    /*shape_ptr->func();*/

    // static binding
    Ellipse ellipse2 { 8, 5, "Ellipse2" };
    ellipse2.func();

    /*ellipse2.draw();*/

    // derived part is sliced off
    Shape shape{ Ellipse{ 2, 2, "Ellipse3" } };
    shape.draw();

    return 0;
}