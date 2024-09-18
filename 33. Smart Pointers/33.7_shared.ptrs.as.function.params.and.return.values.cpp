//
// Created by Εκλεκτός εν Χριστώ on 4/24/24.
//

/*
 * shared pointer as a parameter - when passed by value, this will create a local shared pointer
 * to the function and reference count is going to increment
 *
 * don't return shared ptr by reference, this might left the shared ptr dangling and causes
 * crash when access in the caller
 */

#include <iostream>
#include "Dog.h"
#include <memory>

void pass_by_value(std::shared_ptr<Dog> dog)
{
    std::cout << "Inside func by value : " << dog->get_name() << '\n';
    std::cout << "count in function : " << dog.use_count() << '\n';
}

void pass_by_non_const_ref(std::shared_ptr<Dog>& dog)
{
    dog->set_name("main_dog_changed");
    std::cout << "Inside func non const ref : " << dog->get_name() << '\n';
    std::cout << "count in function : " << dog.use_count() << '\n';
}

void pass_by_const_ref(const std::shared_ptr<Dog>& dog)
{
    // ptr is const, can't be changed or set to null
    // dog.reset();
    dog->set_name("main_dog_changed");
    std::cout << "Inside func const ref : " << dog->get_name() << '\n';
    std::cout << "count in function : " << dog.use_count() << '\n';
}

std::shared_ptr<Dog> return_by_value(std::shared_ptr<Dog>& dog)
{
    dog->set_name("dog_returned");
    std::cout << "Inside func return by value : " << dog->get_name() << '\n';
    std::cout << "count in function : " << dog.use_count() << '\n';
    return dog;
}

std::shared_ptr<Dog>& return_by_ref(std::shared_ptr<Dog>& dog)
{
    dog->set_name("dog_returned by ref");
    std::cout << "Inside func return by ref : " << dog->get_name() << '\n';
    std::cout << "count in function : " << dog.use_count() << '\n';
    return dog;
}

int main()
{
    std::shared_ptr<Dog> dog{ std::make_shared<Dog>("main_dog") };

    std::cout << "count in main : " << dog.use_count() << '\n';

    // two shared ptrs are sharing the dog object now, ref. count is 2 in function
    pass_by_value(dog);

    std::cout << "count in main : " << dog.use_count() << '\n';

    // parameter is a ref. to shared_ptr, no copies are created, ref. count remains 1
    pass_by_non_const_ref(dog);

    std::cout << "count in main : " << dog.use_count() << '\n';

    // param is a ref. no copies were made of shared_ptr, so ref. count remains 1
    pass_by_const_ref(dog);

    std::cout << "count in main : " << dog.use_count() << '\n';

    return_by_value(dog);

    std::cout << "count in main : " << dog.use_count() << '\n';

    // param is returned by reference, ref. count remains 1
    return_by_ref(dog);

    std::cout << "count in main : " << dog.use_count() << '\n';

    return 0;
}