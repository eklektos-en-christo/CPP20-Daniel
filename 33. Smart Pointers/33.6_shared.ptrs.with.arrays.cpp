//
// Created by Εκλεκτός εν Χριστώ on 4/22/24.
//

/*
 *
 */

#include <memory>
#include <iostream>
#include "Dog.h"

int main()
{
    std::shared_ptr<int> shared_int_array{ new int[]{ 1, 2, 3, 4, 5 } };
    std::shared_ptr<Dog> shared_dog_array{ new Dog[]{ Dog{"Dan"}, Dog{"Jude"} } };

//    auto raw_from_shared_int{ shared_int_array.get() };

    for (std::size_t i{0}; i < 5; ++i)
    {
        std::cout << shared_int_array.get()[i] << ' ';
    }
    std::cout << '\n';

//    auto raw_from_shared_dog{ shared_dog_array.get() };

    for (std::size_t i{0}; i < 5; ++i)
    {
        std::cout << shared_dog_array.get()[i].get_name() << ' ';
    }
    std::cout << '\n';

    return 0;
}