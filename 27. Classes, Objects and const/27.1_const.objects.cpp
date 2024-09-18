//
// Created by Εκλεκτός εν Χριστώ on 3/9/24.
//

/*
 * const objects : cant be changed and read through const ptr and const ref or by this pointer to the
 * object being accessed or modified
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

    std::string_view get_name() { return dog_name; }
    std::string_view get_breed() { return dog_breed; }
    unsigned int get_age() { return *p_age; }

    void print_dog();
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

void Dog::print_dog()
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
    const Dog d1{ "John", "Titi", 3 };

    /*d1.print_dog();
    d1.set_name("Gohn");*/

    // accessing through a non-const ptr
    /*Dog* dog_ptr{ &d1 };*/

    // non const reference
    /*Dog& dog_ref{ d1 };*/

    const Dog* d_ptr{ &d1 };
    const Dog& d_ref{ d1 };

    return 0;
}