//
// Created by Εκλεκτός εν Χριστώ on 5/9/24.
//

#ifndef PRACTICE_NUMBER_H
#define PRACTICE_NUMBER_H

#include <iostream>

class Number
{
    friend std::ostream& operator<<(std::ostream& os, const Number& number);

    // implicit conversion of int according to the order of int passed - ugly
    /*friend bool operator<(const Number& left, const Number& right);
    friend bool operator<(int left, const Number& right);
    friend bool operator<(const Number& left, int right);

    friend bool operator>(const Number& left, const Number& right);
    friend bool operator>(int left, const Number& right);
    friend bool operator>(const Number& left, int right);

    friend bool operator==(const Number& left, const Number& right);
    friend bool operator==(int left, const Number& right);
    friend bool operator==(const Number& left, int right);

    friend bool operator!=(const Number& left, const Number& right);
    friend bool operator!=(int left, const Number& right);
    friend bool operator!=(const Number& left, int right);

    friend bool operator<=(const Number& left, const Number& right);
    friend bool operator<=(int left, const Number& right);
    friend bool operator<=(const Number& left, int right);

    friend bool operator>=(const Number& left, const Number& right);
    friend bool operator>=(int left, const Number& right);
    friend bool operator>=(const Number& left, int right);*/

public:
    Number() = delete;
    explicit Number(int value);
    ~Number() = default;

    int get_wrapped_int() const { return m_wrapped_int; }

    /*
    bool operator<(const Number& right) const
    {
        return m_wrapped_int < right.m_wrapped_int;
    }*/

    // from 18 overloaded operators to 4 to simplify the logical operators - C++20
    /*auto operator<=>(const Number& right) const = default;
    auto operator<=>(int n) const { return m_wrapped_int <=> n; }

    bool operator==(const Number& right) const { return m_wrapped_int == right.m_wrapped_int; }
    bool operator==(int n) const { return m_wrapped_int == n; }*/

    friend auto operator<=>(const Number& left, const Number& right);
    friend auto operator<=>(int left, const Number& right);

    friend bool operator==(const Number& left, const Number& right);
    friend bool operator==(int left, const Number& right);

private:
    int m_wrapped_int{0};
};

// compiler needs to see the operators
inline auto operator<=>(const Number& left, const Number& right)
{
    return (left.get_wrapped_int() <=> right.get_wrapped_int());
}

inline auto operator<=>(int left, const Number& right)
{
    return (left <=> right.get_wrapped_int());
}

inline bool operator==(const Number& left, const Number& right)
{
    return (left.get_wrapped_int() == right.get_wrapped_int());
}

inline bool operator==(int left, const Number& right)
{
    return (left == right.get_wrapped_int());
}

#endif //PRACTICE_NUMBER_H
