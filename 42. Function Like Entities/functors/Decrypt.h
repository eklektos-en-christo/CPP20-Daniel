//
// Created by Εκλεκτός εν Χριστώ on 7/14/24.
//

#ifndef PRACTICE_DECRYPT_H
#define PRACTICE_DECRYPT_H

class Decrypt
{
public:
    // a functor - overloading the operator()
    char operator()(const char& c)
    {
        return static_cast<char> (c - 10);
    }
};

#endif //PRACTICE_DECRYPT_H
