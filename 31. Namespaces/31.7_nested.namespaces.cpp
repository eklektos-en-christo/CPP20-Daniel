//
// Created by Εκλεκτός εν Χριστώ on 4/14/24.
//

/*
 * nested namespaces : namespaces inside namespaces
 *
 * inner namespaces can access directly from the outer namespaces
 *
 * outer namespaces have to go through the namespaces's name to access the
 * stuff inside inner namespaces
 *
 *
 */

#include <iostream>

namespace Outer
{
    int outer_int{ 200 };

    namespace inner
    {
        int inner_int{ 112 };

        void print_outer_int()
        {
            // direct access
            std::cout << outer_int << '\n';
        }
    }

    void print_inner_int()
    {
        // inner:: is necessary here - no direct access
        std::cout << inner::inner_int << '\n';
    }
}

int main()
{
    // way to access nested namespacess
    Outer::inner::print_outer_int();

    Outer::print_inner_int();

    return 0;
}