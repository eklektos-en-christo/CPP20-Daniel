//
// Created by Εκλεκτός εν Χριστώ on 03/12/2023.
//

/*
 * else if - to test several different conditions
 */

#include <iostream>

const int Pen{ 10 };
const int Marker{ 20 };
const int Eraser{ 30 };
const int Rectangle{ 40 };
const int Circle{ 50 };
const int Ellipse{ 60 };

int main()
{
    int tool{ Ellipse };

    if (tool == Pen)
        std::cout << "Pen is active now\n";
    else if (tool == Marker)
        std::cout << "Marker is active now\n";
    else if (tool == Eraser)
        std::cout << "Eraser is active now\n";
    else if (tool == Rectangle)
        std::cout << "Rectangle is active now\n";
    else if (tool == Circle)
        std::cout << "Circle is active now\n";
    else if (tool == Ellipse)
        std::cout << "Ellipse is active now\n";

    return 0;
}