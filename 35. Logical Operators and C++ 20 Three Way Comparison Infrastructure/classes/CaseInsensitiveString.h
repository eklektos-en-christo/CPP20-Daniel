//
// Created by Εκλεκτός εν Χριστώ on 5/13/24.
//

#ifndef PRACTICE_CASEINSENSITIVESTRING_H
#define PRACTICE_CASEINSENSITIVESTRING_H

#include <iostream>

// we only care about equivalency and not absolute equivalency here
std::weak_ordering case_insensitive_compare(const char* str1, const char* str2)
{
    std::string string1{ str1 };
    std::string string2{ str1 };

    // turn both to uppercase for comparison
    for (auto& c : string1)
        c = std::toupper(c);

    for (auto& c : string2)
        c = std::toupper(c);

    if (string1.compare(string2) > 0)
        return std::weak_ordering::greater;
    else if (string1.compare(string2) == 0)
        return std::weak_ordering::equivalent;
    else
        return std::weak_ordering::less;
}

class CaseInsensitiveString
{
public:
    CaseInsensitiveString(const std::string str) : m_str{str}{}
    CaseInsensitiveString(const char* str) : m_str{str}{}

    std::weak_ordering operator<=>(const CaseInsensitiveString& b) const
    {
        return case_insensitive_compare(m_str.c_str(), b.m_str.c_str());
    }

    std::weak_ordering operator<=>(const char* b) const
    {
        return case_insensitive_compare(m_str.c_str(), b);
    }

    bool operator==(const CaseInsensitiveString& right) const
    {
        return (case_insensitive_compare(m_str.c_str(), right.m_str.c_str())) ==
                std::weak_ordering::equivalent;
    }

private:
    std::string m_str{};
};

#endif //PRACTICE_CASEINSENSITIVESTRING_H
