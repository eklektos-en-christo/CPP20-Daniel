//
// Created by Εκλεκτός εν Χριστώ on 01/01/2024.
//

/*
 * reference: an alias/another name to a variable
 */

#include <iostream>

int main()
{
    int norm_var{ 2 };

    int& ref_norm_var{ norm_var };

    // both are referring to the same data
    std::cout << norm_var << '\n';
    std::cout << ref_norm_var << '\n';

    // both are of same address
    std::cout << &norm_var << '\n';
    std::cout << &ref_norm_var << '\n';

    norm_var = 3;

    // changes made to the reference variable also
    std::cout << ref_norm_var << '\n';

    ref_norm_var = 4;

    // changes made to the normal variable also
    std::cout << norm_var << '\n';

    return 0;
}