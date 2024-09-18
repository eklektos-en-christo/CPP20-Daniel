//
// Created by Εκλεκτός εν Χριστώ on 6/15/24.
//

#ifndef PRACTICE_BULLDOG_H
#define PRACTICE_BULLDOG_H

#include "Dog.h"

class Bulldog : public Dog
{
public:
    Bulldog() = default;
    virtual ~Bulldog() = default;

    // error
//    virtual void run() const override
//    {
//        std::cout << "Bulldog is running: " << m_fur_style << '\n';
//    }
};

#endif //PRACTICE_BULLDOG_H
