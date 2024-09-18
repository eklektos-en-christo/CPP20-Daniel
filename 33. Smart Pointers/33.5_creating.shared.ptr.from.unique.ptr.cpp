//
// Created by Εκλεκτός εν Χριστώ on 4/21/24.
//

/*
 * unique ptr to a shared ptr - by moving the memory ownership of unique ptr to a shared ptr,
 * i.e. using std::move(unique_ptr), unique ptr will become null and shared ptr will own the
 * resource
 *
 * shared ptr to unique ptr - direct conversion is not possible, we might have multiple shared
 * pointers pointing to a resource simultaneously, even if we make one shared ptr unique, then
 * others would still be pointing to the same resource and unique ptr can only own one resource,
 * copies are not allowed
 * we can return a unique pointer to save in the shared ptr, this will move the unique ptr's
 * ownership to a shared ptr, implicitly.
 *
 * prefer to return a unique ptr from a function, it can be converted to a shared ptr, but
 * shared ptr can't be converted to a unique ptr, returned unique ptr from a function can also
 * be saved in another unique, so unique ptr can be saved in both shared and unique ptrs but
 * shared can't be stored in unique ptr
 */

#include "Dog.h"
#include <iostream>
#include <memory>

std::unique_ptr<Dog> get_unique_ptr()
{
    std::unique_ptr<Dog> unique_dog{ std::make_unique<Dog>("Dog from function") };
    return unique_dog;      // return ptr can be used as a shared or a unique ptr
}

int main()
{
    // fundamental and custom objects held by unique ptrs in the heap
    std::unique_ptr<int> unique_int{ std::make_unique<int>(2) };
    std::unique_ptr<Dog> unique_dog{ std::make_unique<Dog>("Jacob") };

    std::cout << unique_int << ", " << unique_dog << '\n';

    // unique ptrs are moved to shared ptrs - converted, unique to shared
    std::shared_ptr<int> shared_int{ std::move(unique_int) };
    std::shared_ptr<Dog> shared_dog{ std::move(unique_dog) };

    std::cout << shared_int.use_count() << '\n';
    std::cout << shared_dog.use_count() << '\n';
    std::cout << shared_int << ", " << shared_dog << '\n';
    std::cout << unique_int << ", " << unique_dog << '\n';      // became null
    //shared_int = unique_int; - not possible

    // shared are copyable
    std::shared_ptr<int> shared_int_copy{ shared_int };
    std::shared_ptr<Dog> shared_dog_copy{ shared_dog };

    std::cout << shared_int_copy.use_count() << '\n';
    std::cout << shared_dog_copy.use_count() << '\n';

    // direct transformation to unique ptr doesn't work, move doesn't work too
    /*std::unique_ptr<int> shared_to_unique_int{ shared_int };
    std::unique_ptr<Dog> shared_to_unique_dog{ std::move(shared_dog) };*/

    // in this - the unique ptr in function gives up the ownership to a shared ptr
    std::shared_ptr<Dog> dog_from_function{ get_unique_ptr() };
    std::cout << "shared : " << dog_from_function.use_count() << '\n';

    // unique from the function moves to unique in main
    std::unique_ptr<Dog> dog_from_function_other{ get_unique_ptr() };
    std::cout << "unique : " << dog_from_function_other->get_name() << '\n';

    return 0;
}