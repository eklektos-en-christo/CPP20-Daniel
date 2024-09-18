//
// Created by Εκλεκτός εν Χριστώ on 3/8/24.
//

/*
 * this pointer : hidden pointer that contains the address of the current object, for which the
 * method is being executed, this also applies to constructors and destructors
 *
 * chained call using this pointer : set the return type as a pointer, and return the this in the
 * return statement, return this;, in case of returning a reference, the return statement should return a
 * de-referenced this pointer, *this
 */

#include <iostream>
#include <string_view>

class Dog
{
public:
    Dog() = default;
    Dog(std::string_view name, std::string_view breed, int age);

    // return this pointer for chaining the function calls
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

    void print_dog();
    ~Dog();

private:
    std::string dog_name{};
    std::string dog_breed{};
    int* p_age{ nullptr };
};

Dog::Dog(std::string_view name, std::string_view breed, int age)
{
    this->dog_name = name;      // one use of this
    dog_breed = breed;
    p_age = new int{ age };

    std::cout << this << " created\n";
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
    std::cout << this << " destroyed\n";
}

int main()
{
    Dog d1{ "Tom", "Desi", 2 };

    d1.print_dog();

    // chaining the function calls
    // one call returns the ptr and another dereferences that ptr to call another member function
    d1.set_name("Gom")->set_breed("Messi")->set_age(5);

    d1.print_dog();

    return 0;
}