//
// Created by Εκλεκτός εν Χριστώ on 7/13/24.
//

/*
 *
 */

#include <iostream>
#include "move_temporaries/BoxContainer.h"

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

    // in each iteration:
    // make_box constructs a local container and then that container is
    // copied to int_box_array and then local container is destroyed - waste of memory
    for (int i{0}; i < 2; ++i)
        int_box_array[i] = make_box(i + 281);

    std::cout << int_box_array[0] << '\n';
    std::cout << int_box_array[2] << '\n';

    return 0;
}