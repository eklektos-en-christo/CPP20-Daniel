//
// Created by Εκλεκτός εν Χριστώ on 4/14/24.
//

/*
 * namespace aliases : setting the another name for namespaces
 *
 * syntax:
 *              namespace alias_name = namespace::namespace::namespace etc.
 */

#include <iostream>

namespace l1
{
    namespace l2
    {
        namespace l3
        {
            const int inside_l3{ 3 };
        }
    }
}

int main()
{
    // creating a namespace alias
    namespace l3_namespace = l1::l2::l3;

    std::cout << l3_namespace::inside_l3 << '\n';

    return 0;
}