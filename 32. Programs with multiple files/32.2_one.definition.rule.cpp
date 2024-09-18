//
// Created by Εκλεκτός εν Χριστώ on 4/14/24.
//

/*
 * ODR : there can't be more than one definitions in the entire program or in translation units
 *
 * exceptions :
 * for classes we can have multiple definitions, but definitions must be in different
 * translation units and not in the same translation unit
 */

#include <iostream>

int free_standing_variable{};

// linker error - redefinition not allowed
/*int free_standing_variable{};*/

void do_something()
{
    std::cout << "do_something() called" << '\n';
}

struct Point
{
    double m_x;
    double m_y;
};

// error - redefinition in the same translation unit
/*struct Point
{
    double m_x;
    double m_y;
};*/

class Person
{
public:
    explicit Person(int age) : m_age{ age }
    {
    }

private:
    int m_age{};
};

int main()
{
    std::cout << free_standing_variable << '\n';
    Point point{};

    Person person{ 20 };

    return 0;
}

