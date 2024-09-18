//
// Created by Εκλεκτός εν Χριστώ on 3/8/24.
//

/*
 * size of objects : generally the member variables are counted for the size of an object
 *
 * boundary alignment : Boundary alignment, also known as data alignment or memory alignment,
 * refers to the practice of aligning data in memory to specific addresses that are multiples
 * of a particular value, usually the size of the data type. The purpose of alignment is to
 * optimize memory access and improve performance, particularly on architectures that have
 * alignment requirements.
 */

#include <iostream>

class Size
{
private:
    int integer{};
    double floating_point{};
    char character{};
};

int main()
{
    Size sz;
    std::cout << sizeof(sz) << '\n';

    return 0;
}