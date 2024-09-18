//
// Created by Εκλεκτός εν Χριστώ on 3/8/24.
//

/*
 * destructors : special functions, called when the objects are destroyed, they are the best place to
 * release the allocated memory in heap
 *
 * destructors are called : when stack or heap object goes out of scope, they are also called when
 * objects are passed by value, they are called when objects are returned by value
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

void dog_destroyed()
{
    Dog test{ "test", "test", 0 };

    // p_test is stack pointer - won't be released implicitly, so explicit deletion
    Dog* p_test{ new Dog{"p_test", "test", 0} };
    delete p_test;
}

int main()
{
    Dog d1{ "Tom", "Desi", 2 };
    Dog d2{ "Tom2", "Desi2", 4 };

    // destructor called for local object test in dog_destroyed()
    dog_destroyed();

    std::cout << "main() died\n";

    return 0;
}