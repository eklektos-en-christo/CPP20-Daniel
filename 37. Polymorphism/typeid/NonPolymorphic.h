//
// Created by Εκλεκτός εν Χριστώ on 6/18/24.
//

#ifndef PRACTICE_NONPOLYMORPHIC_H
#define PRACTICE_NONPOLYMORPHIC_H

#include <iostream>

class StaticBase
{
public:
    void do_something() { std::cout << "StaticBase::do_something() called\n"; }
    ~StaticBase() = default;
};

class StaticDerived : public StaticBase
{
public:
    void do_something() { std::cout << "StaticDerived::do_something() called\n"; }
    ~StaticDerived() = default;
};

#endif //PRACTICE_NONPOLYMORPHIC_H
