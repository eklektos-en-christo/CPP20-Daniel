//
// Created by Εκλεκτός εν Χριστώ on 5/5/24.
//

#ifndef PRACTICE_NUMBER_H
#define PRACTICE_NUMBER_H

#include <iostream>
#include "Point.h"

class Number
{
    friend std::ostream& operator<<(std::ostream& out, const Number& number);

//    friend Number operator+(const Number& left, const Number& right);
    friend Number operator-(const Number& left, const Number& right);
    friend Number operator*(const Number& left, const Number& right);
    friend Number operator/(const Number& left, const Number& right);
    friend Number operator%(const Number& left, const Number& right);

public:
    Number() = default;
    Number(int value);

    int get_wrapped_int() const
    {
        return m_wrapped_int;
    }

    ~Number() {}

    Number operator+(const Number& right) const
    {
        return { m_wrapped_int + right.m_wrapped_int };
    }

    // int to double converter member function, overloaded
    // return type is deduced by the operator - which is double in this case
    // const - function isn't modifying the value
    // explicit - not needed, function performs implicit conversion, explicit will restrict
    // the function to perform implicit conversions
    // explicit will work if we cast the number to double explicitly at the point of call
    // commented out - conflicting with the builtin overloaded binary operators, confused
    // whether convert the type Number to type of right operand
    /*operator double() const
    {
//        std::cout << "Using the member double() to convert\n";
        return static_cast<double>(m_wrapped_int);
    }*/

    // can be used to convert number to point
//    operator Point() const
//    {
//        std::cout << "Using the member Point() to convert\n";
//        // implicit conversion from int to double
//        return Point(m_wrapped_int, m_wrapped_int, m_wrapped_int);
//    }

private:
    int m_wrapped_int{};
};

#endif //PRACTICE_NUMBER_H
