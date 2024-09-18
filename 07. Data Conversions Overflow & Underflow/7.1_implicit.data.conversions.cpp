//
// Created by Εκλεκτός εν Χριστώ on 09/11/2023.
//

/*
 * Implicit type conversion: done by the compiler, they go from smaller type to larger
 * type
 */

#include <iostream>

int main()
{
    int int_type{ 23 };
    double double_type{ 93.98798};

    // expression evaluates to a double type - implicit conversion
    std::cout << sizeof(double_type + int_type) << '\n';

    // type is double
    std::cout << typeid(double_type + int_type).name() << '\n';

    // in assignment operation, right operand will be converted to left operand's type
    std::cout << sizeof(int_type = double_type) << '\n';

    return 0;
}