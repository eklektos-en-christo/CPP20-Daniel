//
// Created by Εκλεκτός εν Χριστώ on 3/21/24.
//

/*
 * marking the member variables as mutable - by this we can modify the variables from a
 * const member function - violation of const correctness
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
    std::string dog_name {};
    std::string dog_breed {};
    unsigned int* p_age{ nullptr };
    mutable std::size_t print_is_called {};
};

Dog::Dog(std::string_view name, std::string_view breed, unsigned int age)
{
    this->dog_name = name;      // one use of this
    dog_breed = breed;
    p_age = new unsigned int{ age };
}

void Dog::print_dog() const
{
    // modifiable in a const member function - specified as mutable
    ++print_is_called;
    std::cout << "Print is called " << print_is_called << " time(s)\n";
}

Dog::~Dog()
{
    delete p_age;
}

int main()
{
    Dog dog{ "test", "test", 1 };
    dog.print_dog();
    dog.print_dog();
    dog.print_dog();
    dog.print_dog();

    return 0;
}