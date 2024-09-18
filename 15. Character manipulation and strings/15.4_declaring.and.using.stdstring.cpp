//
// Created by Εκλεκτός εν Χριστώ on 12/01/2024.
//

/*
 * std::string - can grow and shrink according to the data size
 */

#include <iostream>
#include <string>

int main()
{
    std::string name{};
    std::string planet{ "We live on planet earth" };
    std::string planet2{ planet };
    std::string message(5, 'a');            // use (), not {}
    std::string planet3{ planet, 18, 5 };
    planet2 = "on earth";

    std::cout << name << '\n';
    std::cout << planet << '\n';
    std::cout << planet2 << '\n';
    std::cout << message << '\n';
    std::cout << planet3 << '\n';

    return 0;
}