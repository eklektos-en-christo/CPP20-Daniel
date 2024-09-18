//
// Created by Εκλεκτός εν Χριστώ on 08/02/2024.
//

/*
 * by default, the main has one argument - which is the name of the program
 * When the application is run through the terminal, the name of the program is passed - which is
 * the first argument and additional arguments are passed if they are needed to be used by the
 * main function
 */

#include <iostream>

int main(int arg_count, char** argv)
{
    std::cout << "Total arguments passed to the application : " << arg_count << '\n';

    std::cout << "All the passed arguments : \n";

    for (std::size_t i{0}; i < arg_count; ++i)
    {
        std::cout << argv[i] << '\n';
    }

    return 0;
}