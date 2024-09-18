//
// Created by Εκλεκτός εν Χριστώ on 4/3/24.
//

/*
 * we can initialize any object in C++ using () or {}
 *
 * {} - doesn't allow narrowing conversions
 * () - allows          ,,          ,,
 *
 * if we use {} with aggregates and do narrowing conversion, it won't be allowed
 *
 * () and {} are part of the uniform initialization in C++
 */

#include <iostream>

class Point
{
private:
    double m_x;
    double m_y;

public:
    Point(double x, double y) : m_x{ x }, m_y{ y }
    {
    }
};

int main()
{
    // () - allowed
    Point p1(5.9, 6.7);

    // {} - allowed
    Point p2{ 5.9, 6.7 };

    // () - works with arrays
    int scores[](1, 9, 8, 3);
    std::cout << scores[0];

    return 0;
}