//
// Created by Εκλεκτός εν Χριστώ on 7/17/24.
//

/*
 * reverse iterators : used to traverse containers backward, incrementing the reverse iterator will
 * cause it to mave backward, not forward
 */

#include <iostream>
#include <vector>

template <typename T>
void reverse_print(const T& collection, std::size_t size)
{
    // rbegin() points to the last element
    auto rbegin_it{ collection.rbegin() };

    // rend() points to an element past the first element of the collection
    while (rbegin_it != collection.rend())
    {
        std::cout << *rbegin_it << ' ';
        ++rbegin_it;
    }

    std::cout << '\n';
}

int main()
{
    std::vector<int> int_vector{ 1, 2, 3, 4, 5 };

    reverse_print(int_vector, int_vector.size());

    // normal and reverse iterators can't be compared, they are not the same
    /*std::cout << (int_vector.end() == int_vector.rbegin());*/

    return 0;
}