//
// Created by Εκλεκτός εν Χριστώ on 7/17/24.
//

/*
 * to iterate from the middle or in between the first and end elements, we can add offset to the first
 * and the end iterator, generally done by adding or subtracting values to them
 *
 *
 */

#include <iostream>
#include <vector>

template <typename T>
void print_subset(const T& container, std::size_t begin_offset, std::size_t end_offset)
{
    auto begin{ container.begin() + begin_offset };
    auto end{ container.end() - end_offset };

    while (begin != end)
    {
        std::cout << *begin << ' ';
        ++begin;
    }

    std::cout<< '\n';
}

int main()
{
    std::vector<int> int_vector{ 1, 2, 3, 4, 5 };

    print_subset(int_vector, 1, 1);

    return 0;
}