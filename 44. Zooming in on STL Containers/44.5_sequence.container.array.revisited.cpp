//
// Created by Εκλεκτός εν Χριστώ on 8/6/24.
//

/**
 * std::array - size is fixed, elements are contiguous
 */

#include <iostream>
#include <array>

template <typename T>
void print_collection(const T& collection)
{
    auto it{ collection.begin() };

    while (it != collection.end())
    {
        std::cout << *it << ' ';
        ++it;
    }
    std::cout << '\n';
}

int main()
{
    std::array<int, 5> array{ 1, 8, 6, 3, 2 };

    print_collection(array);

    std::cout << array[3] << '\n';
    std::cout << array.at(3) << '\n';

    std::cout << array[33] << '\n';     // no bound checking

    try
    {
        std::cout << array.at(33) << '\n';  // performs bound checking
    } catch (std::exception& ex)
    {
        std::cout << "Out of range index: " << ex.what() << '\n';
    }

    array.front() = 11;
    array.back() = 22;

    print_collection(array);

    auto raw_ptr{ array.data() };

    while (raw_ptr != array.end())
    {
        std::cout << *raw_ptr << ' ';
        ++raw_ptr;
    }
    std::cout << '\n';

    auto it_reverse{ array.rbegin() };

    while (it_reverse != array.rend())
    {
        std::cout << *it_reverse << ' ';
        ++it_reverse;
    }
    std::cout << '\n';

    std::cout << array.size() << '\n';
    std::cout << array.max_size() << '\n';
    std::cout << array.empty() << '\n';

    array.fill(291);

    print_collection(array);

    std::array<int, 5> array2{ };

    // cross assigning the std::array is possible
    array = array2;

    print_collection(array);
    print_collection(array2);

    int A[2]{};
    int B[2]{};

    // raw arrays can't be cross assigned
    /*A = B;*/

    return 0;
}