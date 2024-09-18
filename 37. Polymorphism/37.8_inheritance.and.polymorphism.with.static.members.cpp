//
// Created by Εκλεκτός εν Χριστώ on 6/14/24.
//

/*
 * static members - associated with the type itself, not with the objects
 * static vars should be created separately for each class if we wanna know the individual
 * class's object count
 */

#include <iostream>
#include "static_members/Shape.h"
#include "static_members/Ellipse.h"

int main()
{
    Shape shape1;
    Shape shape2;
    Shape shape3;

    std::cout << shape3.get_count() << '\n';

    // this increments the m_count of ellipse1 but also increments the shape's m_count
    Ellipse ellipse1;

    // Ellipse contains the static m_count of shape
    // both shape and ellipse can change the m_count now
    std::cout << Ellipse::m_count << '\n';

    Shape* shape_ptr[] { &shape1, &ellipse1 };

    // polymorphic behavior
    for (auto& shape : shape_ptr)
        std::cout << shape->get_count() << ' ';

    return 0;
}