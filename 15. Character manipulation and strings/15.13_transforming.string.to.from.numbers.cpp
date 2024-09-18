//
// Created by Εκλεκτός εν Χριστώ on 16/01/2024.
//

/*
 * to convert from number to string - use std::to_string function
 */

#include <iostream>
#include <string>

int main()
{
    int int_data{ 21011 };

    // from int to std::string
    std::string string{ std::to_string(int_data) };
    std::cout << string << '\n';

    string = std::to_string(2.222f);
    std::cout << string << '\n';

    string = std::to_string(2.2222);
    std::cout << string << '\n';

    std::string num_str{ "2.8976f" };

    // std::string to int
    std::cout << std::stoi(num_str) << '\n';
    std::cout << std::stol(num_str) << '\n';
    std::cout << std::stof(num_str) << '\n';
    std::cout << std::stod(num_str) << '\n';
    std::cout << std::stold(num_str) << '\n';
    std::cout << sizeof(std::stold(num_str)) << " bytes" << '\n';

    std::cout << std::stoull(num_str) << '\n';
    std::cout << sizeof(std::stoull(num_str)) << " bytes" << '\n';



    return 0;
}