//
// Created by Εκλεκτός εν Χριστώ on 4/18/24.
//

#ifndef PRACTICE_32_6_INLINE_VARIABLES_AND_FUNCTIONS_H
#define PRACTICE_32_6_INLINE_VARIABLES_AND_FUNCTIONS_H

#include <iostream>

// making the function inline - we can include it in multiple TUs without an error
inline void test_from_header()
{
    std::cout << "Test from header\n";
}

#endif //PRACTICE_32_6_INLINE_VARIABLES_AND_FUNCTIONS_H
