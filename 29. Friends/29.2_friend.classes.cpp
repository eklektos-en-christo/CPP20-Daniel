//
// Created by Εκλεκτός εν Χριστώ on 4/3/24.
//

/*
 * friend classes - giving the external classes access to our own member variables, they
 * don't have access to this pointer
 *
 * direct member access is not possible for friends, we can only access through objects
 * of the source class
 *
 * syntax : friend class class_name;
 */

#include <iostream>
#include <string>

class Dog
{
public:
    Dog(std::string name, unsigned int age)
            : m_name{ std::move(name) }, m_age{ age }
    {
    }

    // making the external class a friend of Dog
    friend class Cat;

private:
    std::string m_name{};
    unsigned int m_age{};
};

class Cat
{
public:
    Cat(std::string name, unsigned int age)
            : m_name{ std::move(name) }, m_age{ age }
    {
    }

    // Dog is accessible from cat - cat is a friend of dog, modification to dog is
    // possible
    void show_dog_from_cat(Dog& dog)
    {
        dog.m_name = "Duffy";
        std::cout << dog.m_name << ", " << dog.m_age << '\n';
    }

private:
    std::string m_name{};
    unsigned int m_age{};
};

int main()
{
    Cat c1{ "Luna", 3 };
    Dog d1{ "Fluffy", 4 };

    // Cat can access and manipulate the dog - friendship
    c1.show_dog_from_cat(d1);

    return 0;
}