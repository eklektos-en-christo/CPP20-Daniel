//
// Created by Εκλεκτός εν Χριστώ on 09/11/2023.
//

/*
 * constinit: keyword, variable should be initialized at compile time
 */

#include <iostream>

const int value1{ 23 };
constexpr int value2{ 98 };
int value3{ 86 };

// this is initialized at compile time
constinit int age{ 92 };

// const and constinit can be combined
const constinit int age1{ value1 };

// age is not a const, constinit doesn't imply the constness
/*constinit int age2{ age };*/
constinit int age2{ age1 };

int main()
{
    // constinit variables can be modified
    age = 93;
    age2 = 23;

    // constinit can't be used in main()
    /*constinit int test{ 2 };*/

    return 0;
}