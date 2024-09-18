//
// Created by Εκλεκτός εν Χριστώ on 25/02/2024.
//

/*
 * inline functions : inline keyword suggests the compiler to put the function on the
 * place where it is called, avoiding function call overhead, this increases the binary
 * size
 */

#include <iostream>

// we want the definition organized but want to avoid the function call overhead
inline int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    // max definition will be pasted here by the compiler
    std::cout << max(11, 9) << '\n';

    return 0;
}