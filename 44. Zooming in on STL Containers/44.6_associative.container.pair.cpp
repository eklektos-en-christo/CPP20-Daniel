//
// Created by Εκλεκτός εν Χριστώ on 8/6/24.
//

/*
 * std::pair - groups two data components and treat them as a single entity
 *
 * lives in <utility>
 *
 * contains first and second data member which can be used to access the key and value
 *
 * we can collect the components of a pair into variables using auto syntax : auto[var1, var2] = pair
 *
 * auto[] - structured binding, used to unpack the pairs, tuple etc.
 */

#include <iostream>
#include <utility>          // for std::pair
#include <vector>

int main()
{
    // creating a pair, requires key and pair types in <>
    std::pair<int, std::string> pair1{ 189237, "Daniel" };

    // type of the data components is deduced automatically
    auto pair2{ std::make_pair(1923674, "Jacob") };

    // << is not overloaded for std::pair
    /*std::cout << pair1 << '\n';*/

    // data members are accessible directly which contain the key and value
    std::cout << pair1.first << ' ' << pair1.second << '\n';
    std::cout << pair2.first << ' ' << pair2.second << '\n';

    // structured binding - used to unpack the pair's data into variables
    auto [int_key, str_value]{ pair1 };

    std::cout << int_key << ' ' << str_value << '\n';

    // std::pair can deduce the type of the arguments
    std::pair pair3{ 2, 'a' };
    std::cout << pair3.first << ' ' << pair3.second << '\n';

    std::vector<std::pair<int, std::string>> pair_vector{ pair1, pair2, { 2, "hello" } };

    // pair_vector is a dynamic array and each element of this array is a pair
    std::cout << pair_vector[0].first << ' ' << pair_vector[1].second << '\n';

    for (const auto& pair : pair_vector)
    {
        std::cout << "Pair: " << pair.first << ' ' << pair.second << '\n';
    }

    // another syntax to access the pair - structured binding
    for (auto& [key, value] : pair_vector)
    {
        std::cout << "Pair[key, value]: " << key << ' ' << value << '\n';
    }

    return 0;
}