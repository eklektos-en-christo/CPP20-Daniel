//
// Created by Εκλεκτός εν Χριστώ on 4/1/24.
//

/*
 * deleted constructor - disable a constuctor from being used to create an object, we
 * can delete all kind of constructors
 */

#include <iostream>

class Man
{
    unsigned int m_age{};

public:
    // age can't be empty, so disable the default constructor
    Man() = delete;

    // only constructor with age argument can be used
    explicit Man(unsigned int age) : m_age{ age }
    {
    }
};

int main()
{
    // age can't be empty
    /*Man man1;*/

    // age should be passed
    Man man2{ 30 };

    return 0;
}