//
// Created by Εκλεκτός εν Χριστώ on 08/02/2024.
//

/*
 * old enums : there are multiple problems with legacy enum types, so enum class was
 * introduced
 */

#include <iostream>

enum Direction
{
    North,
    East,
    West,
    South
};

enum Tool
{
    Pen,
    Eraser,
    Marker,
    Sketch
};

int main()
{
    Direction direction{ West };
    Tool tool{ Marker };

    std::cout << std::boolalpha;

    // problem with legacy enums - doesn't make sense
    std::cout << (direction == tool) << '\n';
    std::cout << (direction > tool) << '\n';

    return 0;
}