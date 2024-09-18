//
// Created by Εκλεκτός εν Χριστώ on 4/24/24.
//

/*
 * weak pointers : they dont own the data they point to, if they go out of scope, the memory
 * is not released, they don't have -> or dereference operator, they can't read and write
 *
 * cyclic dependency : two shared pointers/objects pointing to each other, reference count is not going
 * to decrement to zero when anyone of them goes out of scope and this will leak the memory,
 * to solve this we can use the weak ptr
 */

#include <memory>
#include <iostream>
#include "Dog.h"
#include "Smart_Person.h"

int main()
{
    std::shared_ptr<int> shared_int{ std::make_shared<int>(9) };
    std::shared_ptr<Dog> shared_dog{ std::make_shared<Dog>("Jimmy") };

    std::weak_ptr<int> weak_int{ shared_int };
    std::weak_ptr<Dog> weak_dog{ shared_dog };

    // weak ptr can't read and write
    /*std::cout << weak_dog->get() << '\n';
    std::cout << *weak_int << '\n';
    std::cout << weak_dog->get_name() << '\n';*/

    // to use weak_ptr, we can convert it to shared ptr
    // lock() will return a shared ptr
    std::shared_ptr<Dog> weak_to_shared{ weak_dog.lock() };
    std::cout << weak_to_shared.use_count() << '\n';            // weak to shared & shared_dog - refcount 2
    std::cout << weak_to_shared.get() << '\n';
    std::cout << weak_to_shared->get_name() << '\n';

    std::shared_ptr<Person> shared_person1{ std::make_shared<Person>("Dan") };
    std::shared_ptr<Person> shared_person2{ std::make_shared<Person>("Jude") };

    // cyclic dependency
    //
    shared_person1->set_friend(shared_person2);
    shared_person2->set_friend(shared_person1);

    // no destructor called for Dan and Jude, they are not released
    // shared ptrs variables destroyed only, not the memory, leakage
    // but weak ptr solves the problem
    std::cout << shared_person1.use_count() << '\n';
    std::cout << shared_person2.use_count() << '\n';

    return 0;
}