//
// Created by Εκλεκτός εν Χριστώ on 4/13/24.
//

/*
 * anonymous namespace : without an explicit name, they can only be used in the
 * translation unit in which they are declared, compiler internally provides a name
 * for them, the name is not accessible, only one anonymous namespace can be used in
 * a single translation unit, other namespaces will be considered the same if they
 * are declared in the same translation unit, namespace in one unit can only be used
 * in that translation unit only
 */

#include <iostream>

// anonymous namespace without a name
namespace
{
    double add(double a, double b);
}

namespace
{
    double add(double a, double b)
    {
        return a + b;
    }
}

int main()
{
    // anonymous namespace names are accessible in the main.cpp only
    std::cout << add(2, 2) << '\n';

    return 0;
}