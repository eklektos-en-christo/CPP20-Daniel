//
// Created by Εκλεκτός εν Χριστώ on 4/19/24.
//

/*
 * unique ptr can also be passed by reference
 *
 * unique ptr can also be returned from a function
 */

#include <memory>
#include <iostream>
#include "Dog.h"
#include "Person.h"

void pass_dog_by_value(std::unique_ptr<Dog> dog)
{
    dog->print_dog();
}

void pass_dog_by_ref(const std::unique_ptr<Dog>& dog)
{
    dog->print_dog();
    dog->set_name("Ghoul");
    dog->print_dog();

    // unique ptr is const declared - can't be modified
    /*dog.reset();*/
}

std::unique_ptr<Dog> return_by_value()
{
    std::unique_ptr<Dog> dog_local{ std::make_unique<Dog>("Local Dog") };
    std::cout << "Inside the func : " << dog_local.get() << '\n';
    return dog_local;
}

int main()
{
    std::unique_ptr<Dog> dog1{ std::make_unique<Dog>("Daniel") };

    // copies not allowed when unique_ptr parameter is passed by value
    /*pass_dog_by_value(dog1);*/

    // moving is allowed
    pass_dog_by_value(std::move(dog1));

    // unique ptr is destroyed in function call, dog1 is set to null when moved to local
    // unique ptr which is in the function
    std::cout << dog1.get() << '\n';

    std::unique_ptr<Dog> dog2{ std::make_unique<Dog>("Sean") };

    Person person1{ "Leon" };

    // copy is also not allowed when function is a member function of some class and take the
    // unique ptr paramter by value
    /*person1.adopt_dog(dog2);*/

    // moving is allowed, dog2 is owned by the unique ptr which is local to the function
    person1.adopt_dog(std::move(dog2));

    // source Dog is null now
    std::cout << dog2.get() << '\n';

    // anonymous objects are moved implicitly
    // copy is not allowed, move is allowed - no copies are made in the below function call
    pass_dog_by_value(std::make_unique<Dog>("Temp Dog"));

    // dog is destroyed after the function call
    // taking the unique ptr by ref. works, copying doesn't work
    pass_dog_by_ref(std::make_unique<Dog>("Ref Dog"));
    std::cout << "In main()\n";

    // no copy is returned
    auto ptr = return_by_value();

    // function is returned by reference of some sort internally - magic
    // addesses are same
    std::cout << "Inside main() : " << ptr << '\n';
    ptr->print_dog();

    return 0;
}