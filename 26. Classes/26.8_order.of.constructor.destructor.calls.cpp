//
// Created by Εκλεκτός εν Χριστώ on 3/8/24.
//

/*
 * order : destructors are called in reverse order, last object is destroyed first
 */

#include <iostream>
#include <string_view>

class Dog
{
public:
    Dog() = default;
    Dog(std::string_view name, std::string_view breed, int age);
    ~Dog();

private:
    std::string dog_name{};
    std::string dog_breed{};
    int* p_age{ nullptr };
};

// defining the function outside the class
Dog::Dog(std::string_view name, std::string_view breed, int age)
{
    dog_name = name;
    dog_breed = breed;
    p_age = new int{ age };
}

// destructor - defined outside the class, cleaning the heap memory on destruction of a dog object
Dog::~Dog()
{
    delete p_age;
    std::cout << dog_name << " has been killed\n";
}

int main()
{
    Dog d1{ "Tom1", "Desi", 2 };
    Dog d2{ "Tom2", "Desi2", 4 };
    Dog d3{ "Tom3", "Desi3", 8 };
    Dog d4{ "Tom4", "Desi4", 16 };

    return 0;
}