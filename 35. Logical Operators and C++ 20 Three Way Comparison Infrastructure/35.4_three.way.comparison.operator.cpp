//
// Created by Εκλεκτός εν Χριστώ on 5/9/24.
//

/*
 * three way comparison operator(spaceship) <=> : tells the <, > or == comparison in one go
 *
 * like the string comparison functions, it doesn't return an int value, it returns a type
 * called strong_ordering or weak_ordering or partial_ordering, return value is comparable to
 * literal 0(not integral 0)
 *
 * strong ordering : used to describe absolute equality in comparisons, possible values it
 * can have are less, equal, greater
 *
 * weak ordering : used to describe non absolute equality in comparisons, Hello and HELLO may
 * be considered equivalent but not equal
 *
 * partial ordering : used to describe incomparable values for a certain type
 *
 * implicit conversions with orderings: strong > weak > partial
 *
 * <=> is mostly setup as a member function
 */

#include <iostream>
#include <string>
#include <limits>   // for NaN

int main()
{
    int x{ 2 };
    int y{ 2 };

    auto result{ x <=> y };

    // <=> doesn't return an int
    /*std::cout << result << '\n';*/

    std::cout << std::boolalpha;
    std::cout << (result > 0) << '\n';
    std::cout << (result < 0) << '\n';
    std::cout << (result == 0) << '\n';
    std::cout << (result >= 0) << '\n';
    std::cout << (result <= 0) << '\n';
    std::cout << (result != 0) << '\n';

    int a{3};
    int b{3};

    // defining feature of strong ordering
    std::cout << (a < b) << '\n';
    std::cout << (a == b) << '\n';      // strong ordering - absolute equality
    std::cout << (a > b) << '\n';

    std::string s1{ "Hello" };
    std::string s2{ "HELLO" };

    // defining feature of weak ordering
    std::cout << (s1 < s2) << '\n';
    std::cout << (s1 > s2) << '\n';
    std::cout << (s1 == s2) << '\n';    // weak ordering - equivalent but not equal

    double d1{1.1};
    double d2{ std::numeric_limits<double>::quiet_NaN() };

    // defining feature of partial ordering
    // partial ordering - can't compare d1 to d2, d2 is not representable in memory
    std::cout << (d1 < d2) << '\n';
    std::cout << (d1 == d2) << '\n';
    std::cout << (d1 > d2) << '\n';

    return 0;
}