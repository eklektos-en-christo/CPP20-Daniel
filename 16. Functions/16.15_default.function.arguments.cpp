//
// Created by Εκλεκτός εν Χριστώ on 22/01/2024.
//

/*
 * only specify the default arguments int the function declaration, in definition, the
 * arguments are not needed
 */

#include <iostream>

// provided default arguments in the function declaration
void compute(int age =  20, double weight = 20.1, double distance = 180.02);

int main()
{
    // different ways to pass arguments when function has default arguments
    compute();
    compute(22);
    compute(25, 30);
    compute(30, 80, 170);

    return 0;
}

// definition doesn't require default arguments - error if provided
void compute(int age, double weight, double distance)
{
std::cout << age + weight + distance << '\n';
}