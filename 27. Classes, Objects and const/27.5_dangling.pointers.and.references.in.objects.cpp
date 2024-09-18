//
// Created by Εκλεκτός εν Χριστώ on 3/21/24.
//

/*
 * avoid dangling pointers and references in the program
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
    const std::string& compile_dog() const;
    const unsigned int* jumps_per_min() const;
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

const std::string& Dog::compile_dog() const
{
    std::string dog_info{ dog_name + dog_breed + std::to_string(*p_age) };
    // dog_info is deleted at the end of this function, dangling reference is returned
    return dog_info;
}

const unsigned int* Dog::jumps_per_min() const
{
    unsigned int jumps{ 5 };
    // jumps - temporary, dangling pointer returned
    return &jumps;
}

Dog::~Dog()
{
    delete p_age;
}

int main()
{
    Dog dog{ "Ron", "Mike", 3 };
    const auto& str_ref{ dog.compile_dog() };

    // crash - accessing a dangling reference
    std::cout << str_ref << '\n';

    // crash - accessing a dangling pointer
    std::cout << *(dog.jumps_per_min()) << '\n';

    std::cout << "done\n";

    return 0;
}