//
// Created by Εκλεκτός εν Χριστώ on 6/18/24.
//

#ifndef PRACTICE_BASE_H
#define PRACTICE_BASE_H

#include <iostream>

class Base
{
public:
    Base()
    {
        std::cout << "Base Ctor called\n";
        this->setup();
    }

    virtual ~Base() { this->clean_up(); std::cout << "Base Dtor called\n"; }

    virtual void setup()
    {
        std::cout << "Base::setup() called\n";
        m_value = 20;
    }

    virtual void clean_up()
    {
        std::cout << "Base::cleanup() called\n";
    }

    int get_value() { return m_value; };

protected:
    int m_value{};
};

#endif //PRACTICE_BASE_H
