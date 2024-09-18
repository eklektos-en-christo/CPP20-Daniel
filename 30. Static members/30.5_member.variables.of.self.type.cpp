//
// Created by Εκλεκτός εν Χριστώ on 4/5/24.
//

/*
 * we can only declare a self type pointer or reference inside the class being declared,
 * if we try to initialize the pointer with an instance, this would lead to infinite
 * recursive calls to the constructor
 *
 * we can declare the self type non inline static and non inline static const member variables but
 * can only initialize them in cpp file
 */

#include <iostream>

class Point
{
    // pointer is just a pointer to the Point and not the Point itself
    Point* point;


    // works
    static Point p;
    static const Point p1;

public:
    // this causes infinite constructor calls - use nullptr instead
    Point() : point{ nullptr }
    {
    }
};

int main()
{
    Point p{};

    return 0;
}