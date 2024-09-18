//
// Created by Εκλεκτός εν Χριστώ on 19/12/2023.
//

/*
 * nested loop: loop inside a loop
 */

#include <iostream>
#include <string>
#include <chrono>
#include <thread>

int main()
{
    const int rows{ 10 };
    const int cols{ 10 };
    std::string pipe { "|  " };
    std::string name { "ANUZ" };

    for (std::size_t i{1}; i <= rows; ++i)
    {
        std::cout << "+";

        for (std::size_t j{1}; j <= cols; ++j)
        {
            std::cout << " ------ ";
            std::cout << "+";
        }

        std::cout << '\n';

        if (i < 10)
        {
            for (std::size_t k{1}; k <= cols; ++k)
            {
                std::cout << "|  $$$$  ";
            }
            std::cout << "|\n";
        }

        if (i < 10)
        {
            for (std::size_t p{0}; p <= 10; ++p)
            {
                if (p < 10)
                    std::cout << pipe << name << "  ";
                else
                {
                    std::cout << "|\n";

                    for (std::size_t k{1}; k <= cols; ++k)
                    {
                        std::cout << "|  $$$$  ";
                    }

                    std::cout << "|";
                }
            }
        }

        std::cout << '\n';
        std::this_thread::sleep_for(std::chrono::milliseconds(900));
    }

    return 0;
}

