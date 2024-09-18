//
// Created by Εκλεκτός εν Χριστώ on 5/5/24.
//

#include "Number.h"

Number::Number(int value) : m_wrapped_int{value}
{
}

std::ostream& operator<<(std::ostream& out, const Number& number)
{
    out << "Number : " << number.m_wrapped_int;
    return out;
}

/*Number operator+(const Number& left, const Number& right)
{
    return {left.m_wrapped_int + right.m_wrapped_int};
}*/

Number operator-(const Number& left, const Number& right)
{
    return {left.m_wrapped_int - right.m_wrapped_int};
}

Number operator*(const Number& left, const Number& right)
{
    return {left.m_wrapped_int * right.m_wrapped_int};
}

Number operator/(const Number& left, const Number& right)
{
    return {left.m_wrapped_int / right.m_wrapped_int};
}

Number operator%(const Number& left, const Number& right)
{
    return {left.m_wrapped_int % right.m_wrapped_int};
}