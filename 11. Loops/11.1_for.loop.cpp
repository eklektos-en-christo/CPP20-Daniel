//
// Created by Εκλεκτός εν Χριστώ on 17/12/2023.
//

/*
 * for loop: for repetitive tasks
 *
 * size_t - type alias representation of unsigned int, used as an iterator in loop,
 * the value of unsigned int is always positive, iterator is accessible only inside
 * the loop body, we can leave out the declaration in for loop
 *
 * it is a bad thing to hard code the value in for loop, good thing is to put the
 * value in a variable
 *
 * we can leave the curly braces {} if it contains only one statement
 */

#include <iostream>
#include <fstream>

int main()
{
    std::ofstream output{ "for_output.txt" };

    const std::size_t count{ 10 };

    // size_t for unsigned int
    for (std::size_t i{ 0 }; i < count; ++i)
    {
        output << "5 x " << i+1 << " = " << 5 * (i + 1) << '\n';
    }

    return 0;
}