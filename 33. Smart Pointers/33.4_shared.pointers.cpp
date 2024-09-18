//
// Created by Εκλεκτός εν Χριστώ on 4/20/24.
//

/*
 * shared pointers : multiple pointers can point to the same data
 *
 * reference count - shared pointers keep track of the total pointers pointing to the same data
 *
 * shared pointer only goes out of scope when reference count is 0
 *
 * copies are allowed with shared pointers
 *
 * shared ptrs are castable to bools
 *
 * use make_shared to avoid new operator syntax, same as make_unique
 */

#include <iostream>
#include <memory>
#include "Dog.h"

int main()
{
    // shared ptr with fundamental types
    {
        std::shared_ptr<int> shared_int{ new int{6} };

        // dereferencing possible
        std::cout << *shared_int << '\n';
        ++(*shared_int);
        std::cout << *shared_int << '\n';

        // reference count - total shared pointers to the shared_int
        std::cout << shared_int.use_count() << '\n';

        // copying allowed
        std::shared_ptr<int> shared_int_copy{ shared_int };
        std::cout << *shared_int_copy << '\n';

        // reference count is incremented on copying
        std::cout << shared_int.use_count() << '\n';
        std::cout << shared_int_copy.use_count() << '\n';

        // both are accessing the same memory
        std::cout << shared_int << ' ' << shared_int_copy << '\n';
    }

    {
        std::shared_ptr<int> shared_int{ new int{99} };

        // initializing the shared ptr to null
        std::shared_ptr<int> init_to_null;
        std::cout << init_to_null << '\n';

        // 2 shared ptrs to an int data
        init_to_null = shared_int;
        std::cout << init_to_null.use_count() << '\n';
        std::cout << shared_int.use_count() << '\n';

        // explicit init. to nullptr
        std::shared_ptr<int> init_to_null_again{ nullptr };
        std::cout << init_to_null_again << '\n';
        init_to_null_again = init_to_null;

        ++(*init_to_null);

        std::cout << *init_to_null << '\n';
        std::cout << *init_to_null_again << '\n';

        // shared ptr to existing data
        // existing ptr will be not be released automatically
        int* existing_int{ new int{82} };

        std::shared_ptr<int> shared_to_existing{ existing_int };

        // necessary
        existing_int = nullptr;

        std::cout << *shared_to_existing << '\n';
        std::cout << shared_to_existing.use_count() << '\n';

        std::cout << existing_int << '\n';
        std::cout << shared_to_existing.get() << '\n';

        // reset will decrement the reference count
        shared_int.reset();
        std::cout << shared_int.get() << '\n';
        std::cout << shared_int.use_count() << '\n';
        std::cout << init_to_null.use_count() << '\n';
        std::cout << init_to_null_again.use_count() << '\n';
    }

    // shared ptr with custom type
    std::shared_ptr<Dog> shared_dog1{ new Dog{ "shared_dog_1" } };
    std::shared_ptr<Dog> shared_dog2{ shared_dog1 };        // copying allowed

    std::cout << "Custom : " << shared_dog1.use_count() << '\n';
    std::cout << "Custom : " << shared_dog2.use_count() << '\n';

    shared_dog2.reset();

    std::cout << "Custom : " << shared_dog1.use_count() << '\n';
    std::cout << "Custom : " << shared_dog2.use_count() << '\n';
    shared_dog2 = shared_dog1;

    std::shared_ptr<Dog> shared_dog3;
    std::cout << shared_dog3.use_count() << '\n';
    shared_dog3 = shared_dog1;
    std::cout << shared_dog3.use_count() << '\n';

    std::shared_ptr<Dog> shared_dog4{ nullptr };
    std::cout << shared_dog4.use_count() << '\n';
    shared_dog4 = shared_dog3;

    std::cout << shared_dog1.use_count() << '\n';
    std::cout << shared_dog2.use_count() << '\n';
    std::cout << shared_dog3.use_count() << '\n';
    std::cout << shared_dog4.use_count() << '\n';

    Dog* raw_dog{ new Dog{ "raw_dog" } };
    std::shared_ptr<Dog> shared_to_raw_dog{ raw_dog };
    raw_dog = nullptr;              // necessary
    shared_to_raw_dog->print_dog();
    std::cout << raw_dog << '\n';

    // use make_shared to avoid using new operator
    std::shared_ptr<Dog> make_shared_dog{ std::make_shared<Dog>("make_shared_dog") };
    make_shared_dog->print_dog();
    std::cout << make_shared_dog.use_count() << '\n';

    std::shared_ptr<Dog> make_shared_dog_copy{ nullptr };
    make_shared_dog_copy = make_shared_dog;

    std::cout << make_shared_dog_copy.use_count() << " " << make_shared_dog.use_count() << '\n';
    make_shared_dog.reset();

    std::cout << make_shared_dog_copy.use_count() << '\n';

    return 0;
}