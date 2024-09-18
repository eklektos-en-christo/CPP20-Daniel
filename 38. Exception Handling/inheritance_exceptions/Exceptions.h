//
// Created by Εκλεκτός εν Χριστώ on 6/25/24.
//

#ifndef PRACTICE_EXCEPTIONS_H
#define PRACTICE_EXCEPTIONS_H

#include <iostream>
#include <string_view>
#include <string>

class SomethingWrong
{
public:
    SomethingWrong() = default;
    SomethingWrong(std::string_view message)
            : m_message{ message }{}

    ~SomethingWrong() = default;

    std::string what() const { return m_message; }

protected:
    std::string m_message{};
};

class Warning : public SomethingWrong
{
public:
    Warning(std::string_view message) : SomethingWrong(message) {}
    std::string what() const { return m_message + " : YELLOW"; }
};

class SmallError : public Warning
{
public:
    SmallError(std::string_view message) : Warning(message) {}
    std::string what() const { return m_message + " : ORANGE"; }
};

class CriticalError : public SmallError
{
public:
    CriticalError(std::string_view message) : SmallError(message) {}
    std::string what() const { return m_message + " : RED"; }
};

#endif //PRACTICE_EXCEPTIONS_H
