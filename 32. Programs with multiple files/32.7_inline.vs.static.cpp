//
// Created by Εκλεκτός εν Χριστώ on 4/18/24.
//

/*
 * inline names - combines all the definition in multiple TUs in one
 *
 * static or anonymous namespace names - doesn't combine the names, each TU will have separate
 * names, even though we defined names identically in all TUs
 *
 * prefer inline to save memory space
 */

#include <iostream>

void print_age_inline1();
void print_age_inline2();

void namespace_print1();
void namespace_print2();

int main()
{
    // both ages in different TUs are referencing the same memory
    print_age_inline1();
    print_age_inline2();

    // both internal linkage names are different - not same in case of anonymous namespaces
    // static variables are also different in both TUs
    namespace_print1();
    namespace_print2();

    return 0;
}