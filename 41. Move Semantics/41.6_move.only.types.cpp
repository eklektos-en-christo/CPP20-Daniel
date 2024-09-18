//
// Created by Εκλεκτός εν Χριστώ on 7/13/24.
//

/*
 * move only types : their copy ctors and assignment operators are deleted, they are movable only
 */

#include "move_only/BoxContainer.h"
#include <memory>

int main()
{
    BoxContainer<int> box1;
    BoxContainer<int> box2;

    // type is move only
    /*box1 = box2;*/

    // moving works
    box1 = std::move(box2);

    // copy ctor is deleted, can't use it
    /*BoxContainer<int> box3{ box2 };*/

    return 0;
}