//
// Created by Εκλεκτός εν Χριστώ on 8/10/24.
//

/*
 * unordered set & unordered map : there is not ordering in their elements, internally uses hashmap,
 * this provides faster operations than set and map
 */

#include <iostream>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>

int main()
{
    // data is ordered in arbitrary manner, duplicates are not allowed
    std::unordered_set<int> unordered_set{ 1, 1, 8, 6, 5, 3, 2 };

    // data is ordered in arbitrary manner, duplicates keys are not allowed
    std::unordered_map<int, std::string> unordered_map{ {2, "Two"},
                                                        {1, "One"},
                                                        {4, "Four"},
                                                        {3, "Three"}};

    auto it_set{ unordered_set.begin() };

    while (it_set != unordered_set.end())
    {
        std::cout << *it_set << ' ';
        ++it_set;
    }
    std::cout << '\n';

    auto it_map{ unordered_map.begin() };

    while (it_map != unordered_map.end())
    {
        std::cout << it_map->first << ' ';
        ++it_map;
    }
    std::cout << '\n';

    return 0;
}