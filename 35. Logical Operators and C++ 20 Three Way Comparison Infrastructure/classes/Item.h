//
// Created by Εκλεκτός εν Χριστώ on 5/11/24.
//

#ifndef PRACTICE_ITEM_H
#define PRACTICE_ITEM_H

#include <iostream>
#include <compare>
#include "Integer.h"

class Item
{
public:
    Item() = default;
    Item(int a, int b, int c) : m_a{a}, m_b{b}, m_c{c} {}
    Item(int i) : Item(i,i,i){}         // for implicit conversions

    // C++20 feature, compiler generates the == and != from this
    // performs memberwise comparison
    /*bool operator==(const Item& right) const = default;*/

    // generates all six logical operators, does memberwise comparison
    /*auto operator<=>(const Item& right) const = default;*/

    // helping the compiler - telling the type of comparison we want
    std::strong_ordering operator<=>(const Item& right) const = default;

private:
    int m_a{};
    int m_b{};
    int m_c{};
    Integer m_i{};
};

#endif //PRACTICE_ITEM_H
