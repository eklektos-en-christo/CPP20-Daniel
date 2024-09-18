//
// Created by Εκλεκτός εν Χριστώ on 3/6/24.
//

/*
 * concept_name auto - valid
 *
 * concept_name auto var_name = func_call or expression - valid also
 *
 */

#include <iostream>
#include <concepts>

double add(auto a, auto b)
{
    return a + b;
}

int main()
{
    // concept failed - requires an integral type, add return a double - error
    /*std::integral auto a{ add(1, 6) };*/

    return 0;
}