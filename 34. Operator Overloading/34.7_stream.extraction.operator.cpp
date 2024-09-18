//
// Created by Εκλεκτός εν Χριστώ on 5/1/24.
//

/*
 * overloading the stream extraction operator>> for inputting the data into Point objects
 */

#include <iostream>
#include "classes/Point.h"

int main()
{
    Point p1{ 33.7, 89.6 };
    Point p2{ 9.93, 8.73 };
    std::cout << p1 << '\n';
    std::cout << p2 << '\n';

    std::cin >> p1 >> p2;

    std::cout << p1 << '\n';
    std::cout << p2 << '\n';

    return 0;
}