//
// Created by Εκλεκτός εν Χριστώ on 7/30/24.
//

/*
 * list : same as forward_list but allows backward traversal also, elements are not contiguous
 * also called a doubly linked list
 */

#include <iostream>
#include <algorithm>
#include <list>

template <typename T>
void print_collection(const T& collection)
{
    auto it_begin{ collection.begin() };

    while (it_begin != collection.end())
    {
        std::cout << *it_begin << ' ';
        ++it_begin;
    }
    std::cout << '\n';
}

int main()
{
    std::list<int> list{ 1, 12, 36, 8, 10 };

    print_collection(list);

    std::cout << list.front() << '\n';
    std::cout << list.back() << '\n';

    // reverse iterators
    auto it_reverse{ list.rbegin() };

    while (it_reverse != list.rend())
    {
        std::cout << *it_reverse << " ";
        ++it_reverse;
    }
    std::cout << '\n';

    std::cout << list.size() << '\n';
    std::cout << list.max_size() << '\n';
    std::cout << std::boolalpha << list.empty() << '\n';

    auto it_insert{ std::find(list.begin(), list.end(), 36) };

    list.insert(it_insert, 13);

    print_collection(list);

    list.pop_back();

    print_collection(list);

    list.emplace(list.begin(), 19);

    print_collection(list);

    list.push_front(22);

    print_collection(list);

    list.resize(5);

    print_collection(list);

    list.resize(10);

    print_collection(list);

    list.resize(4);

    print_collection(list);

    return 0;
}