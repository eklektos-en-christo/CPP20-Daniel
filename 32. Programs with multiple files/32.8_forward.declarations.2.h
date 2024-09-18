//
// Created by Εκλεκτός εν Χριστώ on 4/18/24.
//

#ifndef PRACTICE_32_8_FORWARD_DECLARATIONS_1_H
#define PRACTICE_32_8_FORWARD_DECLARATIONS_1_H

#include <iostream>

class Dog
{
    unsigned int age{ 3 };

public:
    Dog(unsigned int p_age) : age{ p_age }
    {
    }
    void print_dog() const { std::cout << age << '\n'; }
};

#endif //PRACTICE_32_8_FORWARD_DECLARATIONS_1_H
