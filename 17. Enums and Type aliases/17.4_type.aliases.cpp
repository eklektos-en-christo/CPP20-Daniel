//
// Created by Εκλεκτός εν Χριστώ on 08/02/2024.
//

/*
 * type alias - another name for a type
 *
 * type def - older way to do the same thing as type alias, not recommended
 */

#include <iostream>

int main()
{
    // type alias
    using huge_int =  unsigned long long int;

    // using type alias instead of the type
    huge_int huge_number{ 11119191919194 };

    // older way
    typedef unsigned short int short_int;

    short_int s_int{ 18176 };

    return 0;
}