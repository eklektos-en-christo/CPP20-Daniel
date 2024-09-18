//
// Created by Εκλεκτός εν Χριστώ on 8/12/24.
//

/*
 * std::all_of - checks if something applies to all the elements in the collection, takes iterators
 * to both ends and a predicate(a callback to a function)
 *
 * std::begin and std::end - return iterators to beginning and end(past one element) of the collection
 *
 * lives in <algorithm>
 *
 * std::any_of - checks if any one element satisfies the predicate
 *
 * std::none_of - checks if none of the elements satisfy the predicate
 */

#include <iostream>
#include <algorithm>

class DivisibleBy
{
public:
    explicit DivisibleBy(int d) : m_d{ d }{}
    bool operator()(int n) const { return (n % m_d == 0); }

private:
    const int m_d{};
};

bool is_odd(int n)
{
    return (n % 2 != 0);
}

int main()
{
    // any container can be used
    int collection[] {20,21,37,25};

    auto result
    {
        std::all_of(std::begin(collection), std::end(collection), [](int x){
            return (x % 2 == 0);
        })
    };

    if (result)
        std::cout << "All the elements are even\n";
    else
        std::cout << "All the elements are not even\n";

    // passing functor as a predicate
    auto result1{ std::any_of(std::begin(collection), std::end(collection), DivisibleBy(4)) };

    if (result1)
        std::cout << "At least one number is divisible\n";
    else
        std::cout << "No number is divisible\n";

    auto result2{ std::none_of(std::begin(collection), std::end(collection), is_odd) };

    if (result1)
        std::cout << "Not all are odds\n";
    else
        std::cout << "All are odds\n";

    return 0;
}