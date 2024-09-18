//
// Created by Εκλεκτός εν Χριστώ on 6/18/24.
//

#ifndef PRACTICE_POLYMORPHIC_H
#define PRACTICE_POLYMORPHIC_H

#include <iostream>

class DynamicBase
{
public:
    virtual void do_something() { std::cout << "DynamicBase::do_something() called\n"; }
    virtual ~DynamicBase() = default;
};

class DynamicDerived : public DynamicBase
{
public:
    virtual void do_something() override { std::cout << "DynamicDerived::do_something() called\n"; }
    virtual ~DynamicDerived() = default;
};

#endif //PRACTICE_POLYMORPHIC_H
