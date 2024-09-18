//
// Created by Εκλεκτός εν Χριστώ on 4/4/24.
//

/*
 * inline static member variables : which can be initialized inside the class definition, C++17
 */

#include <iostream>

class Static
{
    // works
    inline static int s_member{0};
};

int main()
{
    return 0;
}