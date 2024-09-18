//
// Created by Εκλεκτός εν Χριστώ on 7/13/24.
//

/*
 * std::move - casts its parameter to a rvalue, when we have a rvalue from a lvalue, we can move it
 * to the destination object by move ctor or move assign
 *
 * lvalues generally call copy ctor or copy assign when assigned
 *
 * syntax: std::move(put the lvalue here)
 *
 * after moving the data from src, we can use src also to add new data, it is not useless
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

// a and b are lvalues
// std::move converts them to rvalues, this triggers the move ctor and assign
// instead of copy ctor and assign
template <class T>
void swap_values(T& a, T& b)
{
    T temp{ std::move(a) };
    a = std::move(b);
    b = std::move(temp);
}

int main()
{
    BoxContainer<int> int_box1;
    populate_box(int_box1, 189);
    BoxContainer<int> int_box2;
    populate_box(int_box2, 101);

    std::cout << "Box1: " << int_box1 << '\n';
    std::cout << "Box2: " << int_box2 << '\n';

    swap_values(int_box1, int_box2);

    std::cout << "Box1: " << int_box1 << '\n';
    std::cout << "Box2: " << int_box2 << '\n';

    return 0;
}