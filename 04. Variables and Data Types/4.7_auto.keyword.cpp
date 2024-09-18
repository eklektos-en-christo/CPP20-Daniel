//
// Created by Εκλεκτός εν Χριστώ on 16/10/2023.
//

#include <iostream>

int main()
{
    // compiler deducing the type
    auto my_var{ 22 + 'e'};
    std::cout << my_var << '\n';

    // my_var deduced as an integer
    std::cout << typeid(my_var).name() << '\n';
    std::cout << sizeof(my_var) << '\n';

    return 0;
}