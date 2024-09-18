//
// Created by Εκλεκτός εν Χριστώ on 8/13/24.
//

/*
 * std::for_each - applies the given predicate to the elements of the container
 */

#include <iostream>
#include <algorithm>
#include <vector>

struct Sum
{
    void operator()(int n) { sum += n; }
    int sum{ 0 };
};

int main()
{
    std::vector<int> vector{ 1, 2, 3, 4, 5 };

    auto print{ [](int n){ std::cout << n << ' '; } };

    // predicate print prints each element of the container
    std::for_each(std::begin(vector), std::end(vector), print);
    std::cout << '\n';

    // int& n will allow us to modify the collection
    auto modify_print{ [](int& n){ ++n; std::cout << n << ' '; } };

    std::for_each(std::begin(vector), std::end(vector), modify_print);
    std::cout << '\n';

    // modified collection
    std::for_each(std::begin(vector), std::end(vector), print);
    std::cout << '\n';

    Sum s {};
    // for_each returns a function object and is necessary to be stored in s - functor
    s = std::for_each(std::begin(vector), std::end(vector), s);

    std::cout << s.sum << '\n';

    // another way of doing the same thing
    int our_result{ 0 };
    std::for_each(std::begin(vector), std::end(vector),
                  [&our_result](int n) { our_result += n; });

    std::cout << our_result << '\n';

    return 0;
}