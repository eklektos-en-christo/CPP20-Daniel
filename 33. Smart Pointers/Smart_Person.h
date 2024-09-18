//
// Created by Εκλεκτός εν Χριστώ on 4/24/24.
//

#ifndef PRACTICE_SMART_PERSON_H
#define PRACTICE_SMART_PERSON_H

#include <memory>
#include <string>

class Person
{
public:
    Person() = default;
    Person(std::string name);
    ~Person();

    void set_friend(std::shared_ptr<Person> p)
    {
        m_friend = p;
    }

private:
    // cyclic dependency problem
    /*std::shared_ptr<Person> m_friend;*/

    // weak ptr when goes out of scope, it wont release the memory
    // so other shared ptr which is pointing to weak ptr can release the memory without leakage
    std::weak_ptr<Person> m_friend;
    std::string m_name{ "Unnamed" };
};

#endif //PRACTICE_SMART_PERSON_H
