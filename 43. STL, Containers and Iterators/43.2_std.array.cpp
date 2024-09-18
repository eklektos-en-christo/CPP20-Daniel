//
// Created by Εκλεκτός εν Χριστώ on 7/16/24.
//

/*
 * std::array - fixed size container for collection of data, lives in <array> header
 */

#include <iostream>
#include <experimental/array>
#include <array>

template <typename T, std::size_t size>
void print_array(std::array<T, size> array)
{
    for (std::size_t i{0}; i < array.size(); ++i)
        std::cout << array[i] << ' ';
    std::cout << '\n';
}

template <typename T>
void print_raw_array(const T* ptr, std::size_t size)
{
    for (std::size_t i{0}; i < size; ++i)
        std::cout << ptr[i] << ' ';
    std::cout << '\n';
}

int main()
{
    std::array<int, 2> array_junk{};
    print_array(array_junk);

    std::array<int, 5> array1{ 1, 2, 3, 4, 5 };
    print_array(array1);

    // auto type and size deduction
    std::array array2{ 2, 4, 8, 10 };
    print_array(array2);

    // auto type and size deduction
    auto make_array{ std::experimental::make_array(1, 2, 3) };
    print_array(make_array);

    std::array<int, 5> array3{};
    array3[0] = 2;
    array3[1] = 4;
    array3[2] = 8;

    std::cout << array3.at(1) << '\n';
    std::cout << array3.front() << '\n';
    std::cout << array3.back() << '\n';

    // data returns the raw pointer to the underlying fixed array
    print_raw_array(array3.data(), array3.size());

    return 0;
}