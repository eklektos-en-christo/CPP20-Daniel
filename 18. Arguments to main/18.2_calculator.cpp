//
// Created by Εκλεκτός εν Χριστώ on 11/02/2024.
//

/*
 *
 */

#include <iostream>
#include <cstdlib>
#include <cstring>

int main(int argc, char** argv)
{
    if (argc != 4)
    {
        std::cerr << "Program can only be called with 3 arguments like : ";
        std::cerr << "./program_name 2 + 2\n";
        std::cerr << "You entered :";

        for (std::size_t i{0}; i < argc; ++i)
            std::cout << ' ' << argv[i];
        std::cout << '\n';

        std::cout << "Ending the program!!\n";
        return 0;
    }

    double first_num{ atof(argv[1]) };
    double second_num{ atof(argv[3]) };

    if ((first_num == 0.0) || (second_num == 0.0))
    {
        std::cerr << "Please use the valid numbers, different from zero!\n";
        return 0;
    }

    const char* operation{ argv[2] };
    char c{};

    if ((std::strlen(operation) == 1) &&
        ((operation[0] == '+') ||
         (operation[0] == '-') ||
         (operation[0] == 'x') ||
         (operation[0] == '/'))
         )
    {
        c = operation[0];
    }
    else
    {
        std::cerr << operation[0] << " is not a valid operation\n";
        std::cout << "Valid operations are : +, -, x and /\n";
        return 0;
    }

    switch (c)
    {
        case '+' :
            std::cout << first_num << " + " << second_num << " : ";
            std::cout << first_num + second_num << '\n';
            break;

        case '-' :
            std::cout << first_num << " - " << second_num << " : ";
            std::cout << first_num - second_num << '\n';
            break;

        case 'x' :
            std::cout << first_num << " x " << second_num << " : ";
            std::cout << first_num * second_num << '\n';
            break;

        case '/' :
            std::cout << first_num << " / " << second_num << " : ";
            std::cout << first_num / second_num << '\n';
            break;

        default : std::cout << "?????\n";
    }

    std::cout << "Program finished\n";

    return 0;
}