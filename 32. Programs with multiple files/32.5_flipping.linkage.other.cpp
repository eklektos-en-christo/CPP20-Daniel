//
// Created by Εκλεκτός εν Χριστώ on 4/17/24.
//

#include <iostream>

extern const double light_speed;

void some_function();
void test();

void do_something_other()
{
    std::cout << "Other file : " << light_speed << '\n';

    // linkage has been flipped to internal, inaccessible now
    /*some_function();*/

    // test is accessible in other TU only where it is declared
    test();
}