//
// Created by Εκλεκτός εν Χριστώ on 25/02/2024.
//

/*
 * capture list - used to capture the items outside of the lambda function to use them
 * inside the lambda
 *
 * capturing by value : we have the copy of the outside variables in the lambda function
 *
 * capturing by reference : working on the original value inside the lambda function
 */

#include <iostream>

int main()
{
    int x{ 1 };
    int y{ 1 };

    // capturing x and y by value, both are copies inside the lambda
    auto capture_list{ [x, y](){ std::cout << "Inner x + y : " << x + y << '\n'; }++x; };

    for (std::size_t i{0}; i < 5; ++i)
    {
        capture_list();
        std::cout << "Outer x + y : " << x + y << '\n';
        ++x; ++y;
    }

    std::cout << '\n';

    // capturing by reference
    auto capture_list_ref{ [&x, &y](){ std::cout << "Inner x + y : " << x + y << '\n'; } };

    // modifying the original value
    for (std::size_t i{0}; i < 5; ++i)
    {
        capture_list_ref();
        std::cout << "Outer x + y : " << x + y << '\n';
        ++x; ++y;
    }

    return 0;
}