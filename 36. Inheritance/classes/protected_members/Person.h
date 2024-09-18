//
// Created by Εκλεκτός εν Χριστώ on 5/19/24.
//

#ifndef PRACTICE_PERSON_H
#define PRACTICE_PERSON_H

#include <iostream>
#include <string>
#include <string_view>

class Person
{
    friend std::ostream& operator<<(std::ostream& out, const Person& person);

public:
    Person() = default;
    Person(std::string_view fname, std::string_view lname);
    ~Person() = default;

// derived classes can access these now when they inherit publicly from this class
// but outside the classes they are not accessible to public
protected:
    std::string m_fname{};
    std::string m_lname{};
};

#endif //PRACTICE_PERSON_H
