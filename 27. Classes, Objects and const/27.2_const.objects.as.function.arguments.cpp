//
// Created by Εκλεκτός εν Χριστώ on 3/19/24.
//

/*
 * same rules apply when passing const objects to functions
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

/* functions taking dog objects */
void take_by_value(Dog d)
{
    d.set_age(2);
    d.print_dog();
}

void take_by_ref(Dog& d)
{
    d.set_name("hell");
    d.print_dog();
}

/*void take_by_const_ref(const Dog& d)
{
    d.set_name("hell");
    d.print_dog();
}*/

void take_by_ptr(Dog* d)
{
    d->set_name("hei");
    d->print_dog();
}

/*void take_by_ptr_const(const Dog* d)
{
    d->set_name("hei");
    d->print_dog();
}*/

int main()
{
    const Dog d1{ "Lenn", "Pitbull", 5 };

    take_by_value(d1);
    /*take_by_ref(d1);*/
    /*take_by_const_ref(d1);*/
    /*take_by_ptr(&d1);*/
    /*take_by_ptr_const(&d1);*/

    return 0;
}