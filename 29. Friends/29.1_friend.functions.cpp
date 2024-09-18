//
// Created by Εκλεκτός εν Χριστώ on 4/3/24.
//

/*
 * friends : to our class, this gives the access of our own members to external entities
 * external entities can be either functions or classes
 *
 * we declare the functions as friends inside the class using "friend" keyword before
 * the function prototype
 *
 * friends don't have the access to this pointer
 *
 * syntax: friend func_prototype;
 */

#include <iostream>
#include <string>
#include <utility>

class Dog
{
public:
    Dog(std::string name, unsigned int age)
        : m_name{ std::move(name) }, m_age{ age }
    {
    }

    // declaring the outer function as a friend of the class
    friend void dog_by_ref(const Dog& dog);

private:
    std::string m_name{};
    unsigned int m_age{};
};

void dog_by_ref(const Dog& dog)
{
    // function can access the private members now
    std::cout << dog.m_name << ", " << dog.m_age << '\n';
}

int main()
{
    Dog d1{ "Jim", 2 };
    dog_by_ref(d1);

    return 0;
}