//
// Created by Εκλεκτός εν Χριστώ on 4/20/24.
//

/*
 * arrays can also be managed by using unique pointers
 *
 * braced initialization doesn't work with make_unique
 */

#include <memory>
#include <iostream>
#include "Dog.h"

int main()
{
    // a stack array
    Dog d_array1[]{ Dog{"Dan"}, Dog{"Ham"}, Dog{"Rich"} };

    for (std::size_t i{0}; i < 3; ++i)
    {
        std::cout << "Static : ";
        d_array1[i].print_dog();
    }

    // allocating on heap
    Dog* p_dog{ new Dog[]{ Dog{"Jan"}, Dog{"Pam"}, Dog{"Lich"} } };

    for (std::size_t i{0}; i < 3; ++i)
    {
        std::cout << "Dynamic : ";
        p_dog[i].print_dog();
    }

    // necessary
    delete[] p_dog;

    // using the smart pointers - better than the above method
    auto uptr_dog{ std::unique_ptr<Dog[]>{ new Dog[]{ Dog{"Tan"}, Dog{"sam"}, Dog{"dich"} } } };

    for (std::size_t i{0}; i < 3; ++i)
    {
        std::cout << "Unique ptr : ";
        uptr_dog[i].print_dog();
    }

    // no need to deallocate explicitly - unique pointer handles the deallocation

    // allocating using make_unique - individual element cant be initialized using this method
    auto uptr_make_uniq_dog{ std::make_unique<Dog[]>(3) };

    for (std::size_t i{0}; i < 3; ++i)
    {
        std::cout << "Make Unique ptr : ";
        uptr_make_uniq_dog[i].print_dog();
    }

    return 0;
}