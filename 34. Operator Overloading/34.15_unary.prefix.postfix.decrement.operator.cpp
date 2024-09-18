//
// Created by Εκλεκτός εν Χριστώ on 5/8/24.
//

#include <iostream>
#include "classes/Point.h"

int main()
{
    Point p1{ 10, 10 };
    --p1;
    std::cout << p1 << '\n';

    std::cout << p1-- << '\n';
    std::cout << p1 << '\n';

    return 0;
}