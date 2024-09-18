//
// Created by Εκλεκτός εν Χριστώ on 7/8/24.
//

/*
 * we can specialize class functions to work differently with some types, this saves the code duplication
 * and reduces the code, because the whole class is not specialized but functions only
 */

#include <iostream>
#include "function_specialization/BoxContainer.h"

int main()
{
    BoxContainer<int> int_box;

    int_box.add(3);
    int_box.add(6);
    int_box.add(2);
    int_box.add(5);

    std::cout << int_box << '\n';
    std::cout << int_box.get_max() << '\n';

    char c1[]{ "Hello" };
    char c2[]{ "there" };
    char c3[]{ "world" };

    BoxContainer<char*> char_box;

    char_box.add(c1);
    char_box.add(c2);
    char_box.add(c3);

    std::cout << char_box << '\n';

    // this calls the specialized get_max for char*
    std::cout << char_box.get_max() << '\n';

    return 0;
}