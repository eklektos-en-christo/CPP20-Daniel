//
// Created by Εκλεκτός εν Χριστώ on 4/19/24.
//

#ifndef PRACTICE_DOG_H
#define PRACTICE_DOG_H

#include <string>
#include <iostream>

class Dog
{
public:
    explicit Dog(std::string name);
    Dog() = default;
    ~Dog();

    void print_dog() const
    {
        std::cout << "Dog : " << m_name << '\n';
    }

    std::string get_name() const
    {
        return m_name;
    }

    void set_name(const std::string& name)
    {
        m_name = name;
    }

private:
    std::string m_name{ "Elliot" };
};

#endif //PRACTICE_DOG_H
