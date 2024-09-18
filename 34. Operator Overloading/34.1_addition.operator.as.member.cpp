//
// Created by Εκλεκτός εν Χριστώ on 4/25/24.
//

/*
 * operator overloading : using the inbuilt operators with our own types for performing
 * operations
 *
 * syntax:
 *          return_type operator[x](params)
 *          {   // body
 *          }
 * we can define the overloaded operator as a member of the class or as a non member(may be friend)
 */

#include "classes/Point.h"
#include <iostream>

int main()
{
    Point p1{ 50, 50 };
    Point p2{ 50, 50 };

    // operator+ returns a new Point object, print_info can be called from that object
    (p1 + p2).print_info();

    return 0;
}