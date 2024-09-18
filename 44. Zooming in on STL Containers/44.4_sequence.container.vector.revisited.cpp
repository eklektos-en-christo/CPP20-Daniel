//
// Created by Εκλεκτός εν Χριστώ on 8/4/24.
//

/*
 * vector - fast access, data is stored contiguously, supports random access with operator[], supports
 * forward and backward traversal, inserting to the front on in the middle is expensive,
 */

#include <iostream>
#include <vector>

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
    std::vector<int> int_vec{ 1, 2, 3, 4, 5 };

    print_collection(int_vec);

    std::cout << int_vec[1] << '\n';
    std::cout << int_vec.at(1) << '\n';

    std::cout << int_vec[22] << '\n';              // no bound checking
    //std::cout << int_vec.at(22) << '\n';        // performs bound checking

    std::cout << int_vec.front() << '\n';
    std::cout << int_vec.back() << '\n';

    // returns a pointer to the underlying data
    std::cout << *(int_vec.data()) << '\n';

    // reverse iterator
    auto it_reverse{ int_vec.rbegin() };

    while (it_reverse != int_vec.rend())
    {
        std::cout << *it_reverse << ' ';
        ++it_reverse;
    }
    std::cout << '\n';

    std::cout << int_vec.max_size() << '\n';
    std::cout << int_vec.size() << '\n';
    std::cout << int_vec.capacity() << '\n';
    std::cout << int_vec.empty() << '\n';       // if vector is empty - bool

    // insert at 2
    auto it_insert{ int_vec.begin() + 1 };

    // it_insert is invalidated - solution is to use new iterator for insertion
    int_vec.insert(it_insert, 22);
    std::cout << *it_insert << '\n';
    int_vec.insert(it_insert, 33);
    std::cout << *it_insert << '\n';
    int_vec.insert(it_insert, 44);
    std::cout << *it_insert << '\n';

    print_collection(int_vec);

    int_vec.erase(int_vec.begin(), int_vec.begin() + 2);
    int_vec.erase(int_vec.begin() + 1);

    print_collection(int_vec);

    return 0;
}