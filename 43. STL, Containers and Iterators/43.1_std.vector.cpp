//
// Created by Εκλεκτός εν Χριστώ on 7/16/24.
//

/*
 * std::vector - container type, stores the elements in a collection, stores data contiguously, live in
 * <vector> header, internally it uses dynamic arrays
 */

#include <iostream>
#include <vector>

template <typename T>
void print_vector(std::vector<T>& vector)
{
    for (std::size_t i{0}; i < vector.size(); ++i)
        std::cout << vector[i] << ' ';
    std::cout << '\n';
}

template <typename T>
void print_raw_array(const T* p, std::size_t size)
{
    for (std::size_t i{0}; i < size; ++i)
        std::cout << p[i] << ' ';
    std::cout<< '\n';
}

int main()
{
    std::vector<std::string> string_vector{ "This", "is", "a", "string", "vector" };
    std::cout << string_vector[3] << '\n';

    print_vector(string_vector);

    // () syntax creates a vector of 10 items with each value 4
    std::vector<int> int_vector1(10, 4);

    // {} syntax creates a vector of the values specified
    std::vector<int> int_vector2{10, 4};

    print_vector(int_vector1);
    print_vector(int_vector2);

    std::cout << string_vector.at(3) << '\n';
    std::cout << string_vector.front() << '\n';
    std::cout << string_vector.back() << '\n';

    // data() returns the raw pointer to the underlying dynamic array
    print_raw_array(string_vector.data(), string_vector.size());

    int_vector2.push_back(40);
    print_vector(int_vector2);

    string_vector.pop_back();
    print_vector(string_vector);

    return 0;
}