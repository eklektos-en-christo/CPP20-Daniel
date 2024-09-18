//
// Created by Εκλεκτός εν Χριστώ on 04/02/2024.
//

/*
 * enums - a type used to represent a range of values
 * values contained in the enums are enumerators, each enumeration is represented by
 * an integer under the hood, counting starts from 0, specific value can also be
 * given to the each enumerator, negative values can also be used
 *
 * same value can also be used with two enumerators
 *
 * size of an enum is an int, so enum can store the values equivalent to the range
 * of an int
 *
 * default associated type with enum class is int, we can change that
 *
 * syntax to change the underlying type - enum class enum_name : type_name {}
 */

#include <iostream>

// unsigned int - setting the custom type for the enum, by default it is int
enum class Month : unsigned char
{
    // 1 for both enumerators, January assigned to Janu enumerator, it works
    January = 1, Jan = 1, Janu = January,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

int main()
{
    // size of char
    std::cout << sizeof(Month) << '\n';

    // enum_class:: is necessary to access the enumerators
    Month first_month{ Month::February };

    std::cout << static_cast<int>(first_month) << '\n';

    return 0;
}