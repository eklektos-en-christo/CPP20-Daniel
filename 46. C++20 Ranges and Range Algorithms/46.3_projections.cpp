//
// Created by Εκλεκτός εν Χριστώ on 8/16/24.
//

/*
 * Projections : it is passed as a parameter, it takes the data and then transform it according to the
 * logic and then data is passed to the comparator or to the ordering mechanism, they project the
 * data
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include "point/Point.h"

template <typename T>
void print_collection(const T& collection)
{
    for (const auto& element : collection)
        std::cout << element << ' ';
    std::cout << '\n';
}

int main()
{
    std::vector<Point> point_vector{ {1, 8}, {6, 2}, {5, 3} };

    print_collection(point_vector);

    // without projections
    // std::less will use the <=> operator of Point to order the elements
    // Points are sorted on the basis of distance between them
    std::ranges::sort(point_vector, std::less<>{});

    print_collection(point_vector);

    // elements sorted on the basis of X coordinate of Point
    // project will be passed with each point and will return x coordinate of each point
    // std::less will use the returned coordinate from projection to compare
    std::ranges::sort(point_vector, std::less<>{},
                      [](const auto& p){ return p.m_x; });

    print_collection(point_vector);

    // directly passing the member variable as an argument to projection
    // y coordinate is used to sort the point
    // m_y is passed through a pointer to projection, & returns the address of m_y
    std::ranges::sort(point_vector, std::less<>{}, &Point::m_y);

    print_collection(point_vector);



    return 0;
}