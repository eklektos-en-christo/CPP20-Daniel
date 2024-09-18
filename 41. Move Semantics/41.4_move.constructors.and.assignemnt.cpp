//
// Created by Εκλεκτός εν Χριστώ on 7/13/24.
//

/*
 * move ctor and move assignment
 *
 * syntax: it should take the source object as a rvalue reference to tell the compiler that move ctor
 * is working with a temporary object
 *
 *
 *      type(type&& src);       // && is rvalue reference, when compiler sees any rvalue object being
 *                              // copied to or copied from, it will call the move ctor or assignment
 *
 * mechanism for move ctor: assign the src ptr + members to the dest ptr + members and make the
 * src ptr + members null
 *
 * move ctor transfers the ownership of a temporary to new object, steals the temporary data
 * move assign. updates the existing object's state by stealing from a temporary
 *
 * move ctor shouldn't take the src object as a const
 */

#include "move_ctors_assignments/BoxContainer.h"

void populate_box(BoxContainer<int>& box, int modifier)
{
    for (int i{0}; i < 20; ++i)
        box.add((i+1) * modifier);
}

BoxContainer<int> make_box(int modifier)
{
    BoxContainer<int> local_box(20);
    populate_box(local_box, modifier);
    return local_box;
}

int main()
{
    BoxContainer<int> int_box_array[2];

    for (int i{0}; i < 2; ++i)
        int_box_array[i] = make_box(i + 281);

    return 0;
}