//
// Created by Εκλεκτός εν Χριστώ on 7/8/24.
//

/*
 * making non-member operator as a friend of the class template
 *
 * <> or <T> is necessary in friend declaration to make it work
 * the other way is to put the definition for the friend inside the class, under the public specifier
 */

#include <iostream>
#include "stream_insertion/BoxContainer.h"

int main()
{
    BoxContainer<int> int_box;
    int_box.add(1);
    int_box.add(2);

    std::cout << int_box << '\n';

    return 0;
}