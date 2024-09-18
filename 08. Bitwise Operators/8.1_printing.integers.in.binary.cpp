//
// Created by Εκλεκτός εν Χριστώ on 27/11/2023.
//

#include <iostream>
#include <bitset>

int main()
{
    std::cout << "Enter your first name: ";
    std::string name{};
    std::cin >> name;

    std::cout << '\"' << name << "\" in binary:\n";
    for (int count{ 0 }; count < name.length(); ++count)
    {
        std::cout << name[count] << " - ";
        std::cout << std::bitset<16>(name[count]) << '\n';
    }

    return 0;
}