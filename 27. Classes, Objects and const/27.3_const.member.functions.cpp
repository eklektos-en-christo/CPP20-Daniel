//
// Created by Εκλεκτός εν Χριστώ on 3/19/24.
//

/*
 * to solve the problem with const objects - mark the member function as const member functions,
 * use const after the parameter list() and before the body {}
 *
 * we can also overload const member functions and non const member functions
 *
 * const correctness - all the rules used to preserve the constness of a const object
 */

#include <string_view>
#include <iostream>

class Dog
{
public:
    Dog() = default;
    Dog(std::string_view name, std::string_view breed, unsigned int age);

    Dog* set_name(std::string_view dog_name)
    {
        this -> dog_name = dog_name;
        return this;
    }

    Dog* set_breed(std::string_view breed)
    {
        this -> dog_breed = breed;
        return this;
    }

    Dog* set_age(int age)
    {
        *(this->p_age) = age;
        return this;
    }

    std::string_view get_name() const { return dog_name; }
    std::string_view get_breed() const { return dog_breed; }
    unsigned int get_age() const { return *p_age; }

    void print_dog() const;
    ~Dog();

private:
    std::string dog_name{};
    std::string dog_breed{};
    unsigned int* p_age{ nullptr };
};

Dog::Dog(std::string_view name, std::string_view breed, unsigned int age)
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
    const Dog d1{ "Doomed", "Damned", 2000 };

    // reading possible - member functions are marked as const
    std::cout << d1.get_age() << '\n';
    d1.print_dog();

    return 0;
}