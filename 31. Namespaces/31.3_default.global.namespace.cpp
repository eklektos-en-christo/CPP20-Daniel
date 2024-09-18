//
// Created by Εκλεκτός εν Χριστώ on 4/13/24.
//

/*
 * global namespace - namespace outside of other namespaces, namespace that is global to
 * the file
 */

#include <iostream>

void add(int a, int b)
{
    std::cout << "Outer: " << a + b << '\n';
}

namespace non_global
{
    void add(int a, int b)
    {
        std::cout << "Inner: " << a + b << '\n';
    }

    void do_something()
    {
        // to use the stuff from outside of namespace, use ::
        // without ::, the local add() will be called
        ::add(2, 2);
    }
}

int main()
{
    non_global::do_something();

    return 0;
}