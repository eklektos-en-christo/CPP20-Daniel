//
// Created by Εκλεκτός εν Χριστώ on 4/18/24.
//

/*
 * forward declaration - used to introduce a name in a file, definition is not needed
 *
 * instead of including a name in every file, we can forward declare it, linker can find the
 * definition for that name later, in this way the name definition can be changed and will not
 * affect the other name where it will be included - reduced compile time
 * but if we use the definition of the name/class, we need to include the class/name in that TU
 * if we only need a name and not the definition, then we can just forward declare it on the top
 * and code will compile
 */

#include "32.8_forward.declarations.1.h"
#include "32.8_forward.declarations.2.h"

int main()
{
    Farm farm;

    return 0;
}