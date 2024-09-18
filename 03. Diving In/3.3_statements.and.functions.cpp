//
// Created by Εκλεκτός εν Χριστώ on 10/10/2023.
//

#include <iostream>

// this is a function, can be reused again and again
int add_numbers(int x, int y)
{
    return x + y;
}

// challenge
int multiply_numbers(int x, int y)
{
    return x * y;
}

int main()
{
    // below are two statements, each ends with a semicolon
    int first_number{ 3 };
    int second_number{ 7 };

    int sum{ first_number + second_number };
    std::cout << "Sum is: " << sum << '\n';

    // calling the defined function to add two numbers
    std::cout << "Sum is: " << add_numbers(2, 40) << '\n';

    // reusing the function again
    std::cout << "Sum is: " << add_numbers(200, 40) << '\n';

    // testing the challenge code
    std::cout << "Product is: " << multiply_numbers(2, 40) << '\n';

    return 0;
}