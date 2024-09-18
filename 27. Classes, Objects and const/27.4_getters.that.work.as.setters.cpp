//
// Created by Εκλεκτός εν Χριστώ on 3/20/24.
//

/*
 * we can return reference to member variables from getters, so they can be used on the left
 * side as references to member variables and on the right side we can assign values to them,
 * they now work as the setters
 *
 * const object wont work when returning by reference because function are not marked as const,
 * for this we can overload the functions and return as const reference and mark the overloaded
 * function as const
 */

#include <string>
#include <iostream>

class Dog
{
public:
    Dog() = default;
    Dog(const std::string& name, const std::string& breed, unsigned int age);

    // getters returning references - calls to them can be used as setters
    // overloaded name() member function to use them with const objects - const overloading
    std::string& name() { return dog_name; }
    const std::string& name() const { return dog_name; }

    std::string& breed() { return dog_breed; }
    unsigned int& age() { return *p_age; }

    void print_dog() const;
    ~Dog();

private:
    std::string dog_name{};
    std::string dog_breed{};
    unsigned int* p_age{ nullptr };
};

Dog::Dog(const std::string& name, const std::string& breed, unsigned int age)
{
    this->dog_name = name;      // one use of this
    dog_breed = breed;
    p_age = new unsigned int{ age };
}

void Dog::print_dog() const
{
    std::cout << "Name : " << dog_name << '\n';
    std::cout << "Breed : " << dog_breed << '\n';
    std::cout << "Age : " << *p_age << '\n';
}

Dog::~Dog()
{
    delete p_age;
}

int main()
{
    Dog dog{ "Tom", "Lebra", 3 };

    dog.print_dog();
    dog.name() = "Gom";
    dog.breed() = "Debra";
    dog.age() = 2;
    dog.print_dog();

    const Dog d1{ "test", "tet", 22};
    std::cout << d1.name() << '\n';

    return 0;
}