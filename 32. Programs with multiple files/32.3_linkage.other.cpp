//
// Created by Εκλεκτός εν Χριστώ on 4/17/24.
//

#include <iostream>

// age from linkage.cpp has no linkage
/*void doo()
{
    std::cout << age << '\n';
}*/

/*void doo()
{
    // global const from linkage.cpp has internal linkage - not accessible in
    // this TU
    std::cout << global_const << '\n';
}*/

// extern - to use the variable in this TU, although the variable has external linkage
// definition resides in another TU
extern int global_variable;

// declaration for compiler - necessary, although the function has external linkage
void simple_function();

void print_global_from_other_file()
{
    std::cout << ++global_variable << '\n';
    std::cout << "Simple function in other TU : ";
    simple_function();
}