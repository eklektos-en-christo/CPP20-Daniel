//
// Created by Εκλεκτός εν Χριστώ on 16/12/2023.
//

/*
 * if constexpr - condition may be evaluated at compile time, if computation is heavy,
 * it also reduces the code in the final executable file, the branch that fails in
 * the condition evaluation is excluded from the executable, increases the speed
 */

#include <iostream>

int main()
{
    // if branch is excluded from the executable, else is included only - optimization
    if constexpr (false)
        std::cout << "Condition is true\n";
    else
        std::cout << "Condition is false\n";

    return 0;
}