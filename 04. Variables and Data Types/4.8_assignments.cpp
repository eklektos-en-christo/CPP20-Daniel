//
// Created by Εκλεκτός εν Χριστώ on 16/10/2023.
//

#include <iostream>

int main()
{
    // declared and initialized a new variable
    int var1{ 221 };
    std::cout << var1 << '\n';

    // assigning new value to the variable
    var1 = 222;
    std::cout << var1 << '\n';

    auto var2{ "hi" };
    std::cout << var2 << '\n';

    // danger when using auto and assigning the new value
    /*var2 = 180;*/
    std::cout << var2 << '\n';

    return 0;
}