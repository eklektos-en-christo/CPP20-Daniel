//
// Created by Εκλεκτός εν Χριστώ on 6/15/24.
//

/*
 * when the pointer is a base pointer:
 * if the base virtual function is private, then the derived polymorphic function won't be
 * called, compiler will give the error about the base function being private
 *
 * the base access specifier of the virtual will be used to determine whether the derived
 * virtual function is accessible or not, even if the derived function is private
 *
 * when the call is through static binding/non base pointer:
 * the access specifier of the derived class will be checked to determine the call
 */

#include <iostream>
#include "functions_and_access_specifiers/Ellipse.h"
#include <memory>

int main()
{
    // when using a base ptr
    std::shared_ptr<Shape> shape_ptr{ std::make_shared<Ellipse>(4, 3, "Ellipse1") };

    // polymorphic behavior when the base ptr is used, draw is public
    // draw() is private in derived
    // compiler checked the base access specifier
    shape_ptr->draw();

    // func() is private, no polymorphic behavior
//    shape_ptr->func();

    // when using static binding
    // no polymorphic behavior, func is public
    Ellipse ellipse2{ 7, 5, "Ellipse2" };
    ellipse2.func();

    // is private
//    ellipse2.draw();

    // ellipse part is sliced off - static binding
    Shape shape1{ Ellipse{ 2, 1, "Ellipse3" } };
    shape1.draw();

    return 0;
}