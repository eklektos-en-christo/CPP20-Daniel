//
// Created by Εκλεκτός εν Χριστώ on 4/18/24.
//

#ifndef PRACTICE_32_8_FORWARD_DECLARATIONS_1_H
#define PRACTICE_32_8_FORWARD_DECLARATIONS_1_H

// forward declaration
class Dog;

class Farm
{
public:
    // works if only the name is needed
    // won't work if we call member function which is in the Dog class
    void include_dog(const Dog& dog);
};

#endif //PRACTICE_32_8_FORWARD_DECLARATIONS_1_H
