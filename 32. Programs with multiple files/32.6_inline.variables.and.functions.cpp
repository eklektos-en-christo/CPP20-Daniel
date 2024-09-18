//
// Created by Εκλεκτός εν Χριστώ on 4/18/24.
//

/*
 * Marking the names and functions inline - this makes the names and functions unique
 * to that TU only, even if two TUs contain the same names, they will not cause any
 * compiler error, each TU will have its own unique instance of that name
 *
 * for inline to work - names and signature must be same in all the TUs
 *
 * inline makes the name confined to that TU only, they can't be used outside of that TU
 * but we can use those inline names through other names which are not inline and
 * accessible from other TUs
 *
 * compiler is going to combine both names, but in TUs they will be treated as unique, underlying
 * memory will remain same
 *
 * if we have a header that includes some name and we use that header in multiple TUs,
 * there will a redefinition error or a similar kind of error, by making the names
 * inline, we make sure that in each TU we have the unique name, even though the code
 * is duplicated in every TU from the header
 */

#include <iostream>
#include "32.6_inline.variables.and.functions.h"        // duplicate code

void some_function();
void print_length_tu1();
void print_length_tu2();

int main()
{
    // inline function is not accessible in this TU
    /*some_function();*/

    print_length_tu1();
    print_length_tu2();

    test_from_header();

    return 0;
}