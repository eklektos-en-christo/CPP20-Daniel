//
// Created by Εκλεκτός εν Χριστώ on 17/01/2024.
//

/*
 * return statement can also be used inside void returning functions
 */

#include <iostream>

void enter_bar(std::size_t age)
{
    if (age >= 18)
        std::cout << "Go inside the bar!" << '\n';
    else
        std::cout << "Can't go inside!!!" << '\n';
}

int main()
{
    // function calls
    enter_bar(16);
    enter_bar(20);

    // function calls inside a loop
    for (std::size_t age{ 1 }; age <= 20; ++age)
    {
        std::cout << "Age " << age << " : ";
        enter_bar(age);
    }

    return 0;
}