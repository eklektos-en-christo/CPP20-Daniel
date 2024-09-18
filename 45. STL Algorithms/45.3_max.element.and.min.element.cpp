//
// Created by Εκλεκτός εν Χριστώ on 8/13/24.
//

/*
 * max_element : returns the max element in a range
 * min_element : returns the min element in a range
 */

#include <iostream>
#include <algorithm>

int main()
{
    int collection[] { 1, 2, 3, 5, 4, 9, 6, 100 };

    // returns an iterator to the max element
    std::cout << *(std::max_element(std::begin(collection), std::end(collection)))
                    << '\n';

    // returns an iterator to the min element
    std::cout << *(std::min_element(std::begin(collection), std::end(collection)))
              << '\n';

    int number_to_find{ 8 };

    auto distance{ [number_to_find](int x, int y)
    {
        return (std::abs(x - number_to_find) < std::abs(y - number_to_find));
    }};

    // closer to 8 is 9
    std::cout << *(std::min_element(std::begin(collection), std::end(collection),
                                    distance)) << '\n';

    // farthest from 8 is 100
    std::cout << *(std::max_element(std::begin(collection), std::end(collection),
                                    distance)) << '\n';

    // return a pair of iterators
    const auto& [near, far]
    {
        std::minmax_element(std::begin(collection), std::end(collection), distance)
    };

    std::cout << *near << ' ' << *far << '\n';

    return 0;
}