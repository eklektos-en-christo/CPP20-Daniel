//
// Created by Εκλεκτός εν Χριστώ on 8/10/24.
//

/*
 * multiset and multimap - they can store duplicates as opposed to the set and map
 *
 * both are ordered like the set and map
 */

#include <iostream>
#include <set>
#include <map>

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
    std::multiset<int> multiset1{ 1, 1, 2, 3, 4, 2, 3 };
    print_collection(multiset1);                // duplicates are allowed

    // duplicates are allowed
    std::multimap<int, std::string> multimap1{ {1, "data"},
                                               {1, "data"},
                                               {1, "data"},
                                               {1, "data"}};

    auto it{ multimap1.begin() };

    while (it != multimap1.end())
    {
        std::cout << it->first << ' ';
        ++it;
    }
    std::cout << '\n';

    return 0;
}