//
// Created by Εκλεκτός εν Χριστώ on 5/12/24.
//

#ifndef PRACTICE_INTEGER_H
#define PRACTICE_INTEGER_H

struct Integer
{
    Integer() = default;
    Integer(int n) : m_wrapped_int{n}{}
    int get() const { return m_wrapped_int; }

    bool operator==(const Integer& right) const
    {
        return m_wrapped_int == right.m_wrapped_int;
    }

    bool operator<(const Integer& right) const
    {
        return m_wrapped_int < right.m_wrapped_int;
    }

private:
    int m_wrapped_int{};
};

#endif //PRACTICE_INTEGER_H
