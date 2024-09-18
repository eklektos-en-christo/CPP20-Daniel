//
// Created by Εκλεκτός εν Χριστώ on 07/12/2023.
//

/*
 * Switch statement:
 *
 * variable inside switch condition should be an integral type, enums, char, int etc.
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

    switch (tool)
    {
        case Pen:
            std::cout << "Active tool is Pen\n";
            break;
        case Marker:
            std::cout << "Active tool is Marker\n";
            break;
        case Eraser:
            std::cout << "Active tool is Eraser\n";
            break;
        case Rectangle:
            std::cout << "Active tool is Rectangle\n";
            break;
        case Circle:
            std::cout << "Active tool is Circle\n";
            break;
        case Ellipse:
            std::cout << "Active tool is Ellipse\n";
            break;

        default:
            std::cout << "No match found\n";
            break;
    }

    return 0;
}