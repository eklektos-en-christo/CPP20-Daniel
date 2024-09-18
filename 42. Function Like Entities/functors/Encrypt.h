//
// Created by Εκλεκτός εν Χριστώ on 7/14/24.
//

#ifndef PRACTICE_ENCRYPT_H
#define PRACTICE_ENCRYPT_H

class Encrypt
{
public:
    // a functor - overloading the operator()
    char operator()(const char& c)
    {
        return static_cast<char> (c + 10);
    }
};

#endif //PRACTICE_ENCRYPT_H
