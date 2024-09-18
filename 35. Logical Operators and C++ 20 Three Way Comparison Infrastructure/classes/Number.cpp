//
// Created by Εκλεκτός εν Χριστώ on 5/9/24.
//

#include "Number.h"

std::ostream& operator<<(std::ostream& os, const Number& number)
{
    os << "Number : " << number.m_wrapped_int;
    return os;
}

/*bool operator<(const Number& left, const Number& right)
{
    return left.m_wrapped_int < right.m_wrapped_int;
}
bool operator<(int left, const Number& right)
{
    return left < right.m_wrapped_int;
}
bool operator<(const Number& left, int right)
{
    return left.m_wrapped_int < right;
}

bool operator>(const Number& left, const Number& right)
{
    return left.m_wrapped_int > right.m_wrapped_int;
}
bool operator>(int left, const Number& right)
{
    return left > right.m_wrapped_int;
}
bool operator>(const Number& left, int right)
{
    return left.m_wrapped_int > right;
}

bool operator==(const Number& left, const Number& right)
{
    return left.m_wrapped_int == right.m_wrapped_int;
}
bool operator==(int left, const Number& right)
{
    return left == right.m_wrapped_int;
}
bool operator==(const Number& left, int right)
{
    return left.m_wrapped_int == right;
}

bool operator!=(const Number& left, const Number& right)
{
    return left.m_wrapped_int != right.m_wrapped_int;
}
bool operator!=(int left, const Number& right)
{
    return left != right.m_wrapped_int;
}
bool operator!=(const Number& left, int right)
{
    return left.m_wrapped_int != right;
}

bool operator<=(const Number& left, const Number& right)
{
    return left.m_wrapped_int <= right.m_wrapped_int;
}
bool operator<=(int left, const Number& right)
{
    return left <= right.m_wrapped_int;
}
bool operator<=(const Number& left, int right)
{
    return left.m_wrapped_int <= right;
}

bool operator>=(const Number& left, const Number& right)
{
    return left.m_wrapped_int >= right.m_wrapped_int;
}
bool operator>=(int left, const Number& right)
{
    return left >= right.m_wrapped_int;
}
bool operator>=(const Number& left, int right)
{
    return left.m_wrapped_int >= right;
}*/

Number::Number(int value) : m_wrapped_int{value}
{
}

