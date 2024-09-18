//
// Created by Εκλεκτός εν Χριστώ on 4/12/24.
//

/*
 * namespace - feature used to avoid the name conflicts
 *
 * syntax:      namespace_name {conflicting code goes here}
 *
 * we can also use namespaces in both defintion and declaration of functions etc.
 *
 * to access from namespace - namespace_name::whatever_thing_inside_defined
 */

#include <iostream>

namespace no_adjustment
{
    int add(int a, int b)
    {
        return a + b;
    }
}

// only declaration of add
namespace adjustment
{
    int add(int a, int b);
}

int main()
{
    // call add from adjustment namespace
    std::cout << adjustment::add(2, 1) << '\n';

    return 0;
}

// definition of add - works
namespace adjustment
{
    int add(int a, int b)
    {
        return a + b - 1;
    }
}