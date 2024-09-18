//
// Created by Εκλεκτός εν Χριστώ on 25/02/2024.
//

/*
 * static variables : they live throughout the entire application, they are of two types,
 * one is global variables, another are static variables inside a function
 *
 * Global variables : they initialized when the application starts before the main(), they
 * are destroyed when the application ends, they are accessible throughout the entire file
 *
 * static inside functions : their scope is limited to the scope in which they are
 * declared, they are marked as static explicitly
 */

#include <iostream>

// global variable - alive and accessible throughout the program
std::size_t total_dogs{ 3000 };

unsigned int add_student()
{
    static unsigned int student_count{ 0 };
    std::cout << student_count << '\n';
    ++student_count;

    ++total_dogs;

    return student_count;
}

int main()
{
    for (std::size_t i{0}; i < 10; ++i)
    {
        add_student();
    }

    std::cout << total_dogs << '\n';

    return 0;
}