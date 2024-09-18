//
// Created by Εκλεκτός εν Χριστώ on 4/13/24.
//

/*
 * using declarations - to use the items from a namespace without qualifying the item with
 * a namespace using ::
 *
 * to bring a single name into the namespace:
 * using namespace_name::name's_name
 *
 * to bring the entire names from a namespace:
 * using namespace namespace_name;
 *
 * don't import std namespace entirely - conflicts with other names in the project
 */

#include <iostream>
#include "classes/Point.h"
#include "classes/Line.h"
#include "classes/Cylinder.h"

int main()
{
    // this only imports the Point into the main(), other classes can't be used
    using Geometry::Point;
    Point p1;

    // not allowed, only Point is qualified to be used in the main()
    /*Line l1{p1, p1};*/

    // whole namespace is imported - everything from the Geometry can be used in main()
    using namespace Geometry;
    Line l{p1, p1};
    Cylinder cylinder{2, 2};
    Point p2{};

    return 0;
}