//
// Created by Εκλεκτός εν Χριστώ on 01/12/2023.
//

#include <iostream>
#include <bitset>
#include <iomanip>

int main()
{
    unsigned char a{ 0x4 };
    unsigned char b{ 0x7 };

    // AND
    std::cout << "AND:\n";
    std::cout << std::setw(20) << std::bitset<8>(a) << '\n';
    std::cout << std::setw(20) << std::bitset<8>(b) << '\n';
    std::cout << std::setw(20) << "--------" << '\n';
    std::cout << std::setw(20) << std::bitset<8>(a & b) << '\n' << '\n' << "OR:\n";

    // OR
    std::cout << std::setw(20) << std::bitset<8>(a) << '\n';
    std::cout << std::setw(20) << std::bitset<8>(b) << '\n';
    std::cout << std::setw(20) << "--------" << '\n';
    std::cout << std::setw(20) << std::bitset<8>(a | b) << '\n' << '\n' << "NOT:\n";

    // NOT - flip the bits
    std::cout << std::setw(20) << std::bitset<8>(b) << '\n';
    std::cout << std::setw(20) << "--------" << '\n';
    std::cout << std::setw(20) << std::bitset<8>(~b) << '\n' << '\n' << "XOR:\n";

    // XOR - true if only one of the bit is 1
    std::cout << std::setw(20) << std::bitset<8>(a) << '\n';
    std::cout << std::setw(20) << std::bitset<8>(b) << '\n';
    std::cout << std::setw(20) << "--------" << '\n';
    std::cout << std::setw(20) << std::bitset<8>(a ^ b) << '\n' << '\n';

    return 0;
}