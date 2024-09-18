//
// Created by Εκλεκτός εν Χριστώ on 8/21/24.
//

/*
 * input iterators - to input the data
 * output iterators - to output the data
 * forward iterators - to move forward in the container
 * bidirectional iterators - moves forward and backward
 * random access iterators - accessing random elements, like pointer arithmetic
 * contiguous iterators - traverse memory contiguously
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <ranges>

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vector)
{
    for (auto i : vector)
        out << i << ' ';
    std::cout << '\n';

    return out;
}

int main()
{
    std::vector<int> num_vector{ 5, 1, 8, 2, 6, 3, 4 };
    std::cout << num_vector;

    // input iterators
    // cbegin and cend are constant iterators
    // they can be used to read, but they can't write
    if (std::ranges::find(num_vector.cbegin(), num_vector.cend(), 7) != num_vector.cend())
        std::cout << "num_vector contains " << 7 << '\n';
    else
        std::cout << "num_vector doesn't contain " << 7 << '\n';

    std::vector<int> num_vector_dest(num_vector.size());

    // output iterators
    // destination iterator is a const, it can't write to the vector
    /*std::ranges::copy(num_vector.cbegin(), num_vector.cend(), num_vector_dest.cbegin());*/

    // destination iterator should be an output iterator to write to the container
    std::ranges::copy(num_vector.cbegin(), num_vector.cend(), num_vector_dest.begin());

    std::cout << num_vector;
    std::cout << num_vector_dest;

    // forward iterators
    // operator++ is needed to move forward
    std::ranges::replace(num_vector.begin(), num_vector.end(), 1, 9);

    std::cout << num_vector;

    //  bidirectional iterators
    auto it_begin{ num_vector_dest.begin() };
    auto it_end{ num_vector_dest.end() };

    // operator-- and operator++ is needed to traverse backwards
    while (it_end-- != it_begin)
        std::ranges::reverse(num_vector_dest);

    std::cout << num_vector_dest;

    // random access iterator
    std::ranges::sort(num_vector);

    std::cout << num_vector;

    return 0;
}