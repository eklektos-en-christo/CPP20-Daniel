//
// Created by Εκλεκτός εν Χριστώ on 6/15/24.
//

#ifndef PRACTICE_DERIVED_H
#define PRACTICE_DERIVED_H

#include "Base.h"

class Derived : public Base
{
public:
    Derived() = default;
    virtual ~Derived() = default;

    virtual int add(int x=10, int y=10) const override { std::cout << "Derived::add(): "; return x + y; }
};

#endif //PRACTICE_DERIVED_H
