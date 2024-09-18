//
// Created by Εκλεκτός εν Χριστώ on 7/16/24.
//

/*
 * iterators : pointer like types used to traverse the containers
 *
 * iterator is bound to the container and data which it contains, iterator for one type of data won't
 * work with another type
 */

#include <iostream>
#include <vector>
#include <array>

template <typename T>
void print_collection(const T& collection)
{
    auto iter{ collection.begin() };

    while (iter != collection.end())
    {
        std::cout << *iter << ' ';
        ++iter;
    }

    std::cout << '\n';
}

int main()
{
    std::vector<int> int_vector{ 1, 2, 3, 4 };
    std::array<int, 4> int_array{ 20, 30, 10, 11 };

    // setting the iterators to begin and end of the vector, end will point to the past one element in
    // vector and not to the last element in vector
    std::vector<int>::iterator iter_begin{ int_vector.begin() };
    std::vector<int>::iterator iter_end{ int_vector.end() };

    // works like pointer arithmetic
    std::cout << std::boolalpha;
    std::cout << *iter_begin << '\n';
    std::cout << *(iter_begin + 1) << '\n';
    std::cout << (iter_begin == iter_end) << '\n';

    std::cout << *iter_end << '\n';

    print_collection(int_vector);
    print_collection(int_array);

    return 0;
}