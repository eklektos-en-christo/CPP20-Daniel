//
// Created by Εκλεκτός εν Χριστώ on 6/18/24.
//

#ifndef PRACTICE_DERIVED_H
#define PRACTICE_DERIVED_H

#include "Base.h"

class Derived : public Base
{
public:
    Derived() : Base{} { std::cout << "Derived Ctor called\n"; }

    virtual ~Derived() { std::cout << "Derived Dtor called\n"; }

    virtual void setup() override
    {
        std::cout << "Derived::setup() called\n";
        m_value = 100;
    }

    virtual void clean_up() override
    {
        std::cout << "Derived::clean_up() called\n";
    }
};

#endif //PRACTICE_DERIVED_H
