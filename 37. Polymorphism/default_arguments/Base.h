//
// Created by Εκλεκτός εν Χριστώ on 6/15/24.
//

#ifndef PRACTICE_BASE_H
#define PRACTICE_BASE_H

#include <iostream>

class Base
{
public:
    Base() = default;
    virtual ~Base() = default;

    virtual int add(int x=5, int y=5) const { std::cout << "Base::add(): "; return x + y; }
};

#endif //PRACTICE_BASE_H
