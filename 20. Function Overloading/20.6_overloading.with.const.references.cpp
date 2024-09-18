//
// Created by Εκλεκτός εν Χριστώ on 24/02/2024.
//

/*
 * non-const references and const references are both different types, so overloads
 * will work
 */

#include <iostream>

int max(int& a, int& b)
{
    std::cout << "(int&, int&) called\n";
    return (a > b) ? a : b;
}

int max(const int& a, const int& b)
{
    std::cout << "(const int&, const int&) called\n";
    return (a > b) ? a : b;
}

int main()
{
    int a{ 28 };
    int b{ 91 };
    const auto ref_a{ a };
    const auto ref_b{ b };

    max(a, b);
    max(ref_a, ref_b);

    return 0;
}