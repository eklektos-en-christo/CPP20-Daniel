//
// Created by Εκλεκτός εν Χριστώ on 4/27/24.
//

/*
 *
 */

#include <iostream>
#include "classes/Point.h"

int main()
{
    Point p1{ 9.8, 5.1 };

    std::cout << p1[0] << ", " << p1[1] << '\n';

    // left syntax returns a reference to the m_x and m_y which can be used to modify the data
    p1[0] = 9.9;
    p1[1] = 6.6;

    std::cout << p1[0] << ", " << p1[1] << '\n';

    return 0;
}