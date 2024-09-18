//
// Created by Εκλεκτός εν Χριστώ on 4/28/24.
//

/*
 * to print our class using <<, we can overload non member << operator as a friend of the class
 * first operand will be an ostream object and second operand will be our class
 *
 * we can also make ostream as a member function but first operand will then become our class
 * and second operand becomes the ostream class, which is awkward
 */

#include "classes/Point.h"

int main()
{
    Point p1{ 3.8, 9.2 };
    Point p2{ 1.0, 6.7 };

    // awkward, when << is a member of the Point class
    p1 << std::cout;

    // intuitive, operator<< as friend of Point, chaining of statements
    std::cout << p1 << ", " << p2 << '\n';

    return 0;
}