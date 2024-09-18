//
// Created by Εκλεκτός εν Χριστώ on 01/01/2024.
//

/*
 * making a reference const - to prevent the modification of data through reference, the data
 * is treated as const through a reference even if the data itself is non-const, the const
 * keyword is applied to the name of the reference
 *
 */

#include <iostream>

int main()
{
    int data{ 99 };
    const auto& const_ref_data{ data };

    // const reference can't modify the data
    /*++const_ref_data;*/

    return 0;
}