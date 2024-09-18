//
// Created by Εκλεκτός εν Χριστώ on 21/10/2023.
//

#include <iostream>

int main()
{
    int value{ 27 };

    // compound addition, value += 20; is equivalent of value = value + 20; (++ is not same as +=)
    value += 20;
    std::cout << value << '\n';

    // compound multiplication, the value isn't incremented by 1 as it happens in prefix/postfix ++
    value += 2;
    std::cout << value << '\n';

    return 0;
}