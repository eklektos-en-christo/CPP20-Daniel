//
// Created by Εκλεκτός εν Χριστώ on 4/15/24.
//

// error - redefinition of variable contained in 32.2_odr.cpp
/*int free_standing_variable{};*/

// redefinition - allowed, not recommended, allowed because translation unit is different
struct Point
{
    double m_x;
    double m_y;
};

// redefinition - allowed, different translation unit
class Person
{
public:
    explicit Person(int age) : m_age{ age }
    {
    }

private:
    int m_age{};
};