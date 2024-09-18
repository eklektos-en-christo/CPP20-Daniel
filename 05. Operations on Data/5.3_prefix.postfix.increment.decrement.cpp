//
// Created by Εκλεκτός εν Χριστώ on 20/10/2023.
//

#include <iostream>

int main()
{
    int value{ 2 };

    // increment the value by 1 using postfix ++ operator, value++ means value = value + 1
    value++;
    std::cout << value << '\n';

    value--;
    std::cout << value << '\n';

    // prints 2 because value is evaluated first then it is incremented
    std::cout << value++ << '\n';

    // prints 3, because value has been updated in the previous statement
    std::cout << value << '\n';

    // prints 4, because value is incremented first, then it is evaluated
    std::cout << ++value << '\n';

    return 0;
}