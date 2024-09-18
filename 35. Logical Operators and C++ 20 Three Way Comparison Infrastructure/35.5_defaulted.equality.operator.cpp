//
// Created by Εκλεκτός εν Χριστώ on 5/9/24.
//

/*
 * in C++20, we can make operator== default and compiler can generate the operator==
 * definition for us, it performs memberwise comparison inside, compiler also generates a !=
 * operator when generating == operator
 *
 * when the == is setup as a member, implicit conversions will not work for left operand but
 * in c++20, even the left operand will be converted if the operator is a member function,
 * internally compiler re-writes and flips the operands to make this work
 */

#include <iostream>

class Item
{
public:
    Item() = default;
    Item(int a, int b, int c) : m_a{a}, m_b{b}, m_c{c} {}
    Item(int i) : Item(i,i,i){}         // for implicit conversions

    // C++20 feature, compiler generates the == and != from this
    // performs memberwise comparison
    bool operator==(const Item& right) const = default;

private:
    int m_a{};
    int m_b{};
    int m_c{};
};

int main()
{
    Item i1{ 2 };
    Item i2{ 2 };

    std::cout << std::boolalpha;
    std::cout << (i1 == i2) << '\n';
    std::cout << (i1 != i2) << '\n';        // works

    // implicit conversions work even on left operand when operator is defined as a member
    std::cout << (2.2 == i2) << '\n';
    std::cout << (i1 == 2.2) << '\n';
    std::cout << (2.2 != i2) << '\n';
    std::cout << (i1 != 2.2) << '\n';

    return 0;
}