//
// Created by Εκλεκτός εν Χριστώ on 20/12/2023.
//

/*
 * std::rand() - generates random number from 0 to RAND_MAX, everytime the program is
 * run it produces the same number
 *
 * we can control the range of random numbers using % operator
 */

#include <iostream>
#include <iomanip>
#include <ctime>

int main()
{
    int random_num = std::rand();

    std::cout << random_num << '\n';

    for (std::size_t i{0}; i < 10; ++i)
        std::cout << std::rand() << ' ';
    std::cout << '\n';

    // generate random number between 0 to 10
    for (std::size_t i{0}; i < 20; ++i)
        std::cout << std::setw(3) << std::rand() % 11 << ' ';
    std::cout << '\n';

    // from 1 to 10
    for (std::size_t i{0}; i < 20; ++i)
        std::cout << std::setw(3) << (std::rand() % 10) + 1 << ' ';
    std::cout << '\n';

    // giving the seed to rand
    std::srand(std::time(0));

    // from 0 to 10, each time the random number generated is different
    for (std::size_t i{0}; i < 20; ++i)
        std::cout << std::setw(3) << (std::rand() % 10) + 1 << ' ';
    std::cout << '\n';

    return 0;
}