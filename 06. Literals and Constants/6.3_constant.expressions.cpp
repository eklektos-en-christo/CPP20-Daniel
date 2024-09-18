//
// Created by Εκλεκτός εν Χριστώ on 09/11/2023.
//

/*
 * Constant expression: that may evaluate at compile time or runtime
 */

#include <iostream>

int main()
{
    constexpr int SOME_LIB_MAJOR_VERSION{ 12345 };

    // constexpr variable is a constant variable, can't change the value
    /*SOME_LIB_MAJOR_VERSION = 67890;*/

    int init{ 2 };
    // can't initialize and constexpr variable with a runtime variable i.e. init
    /*constexpr int test{ init };*/

    // compile time check - if check fails the compilation stops
    // only the constexpr expression can be used here because check happens at compile time
    static_assert(SOME_LIB_MAJOR_VERSION == 12345);

    return 0;
}