//
// Created by Εκλεκτός εν Χριστώ on 9/7/24.
//

/*
 *
 */

#include <iostream>
#include <coroutine>
#include <cassert>
#include "third_party/unique_generator.h"


unique_generator<int> do_work()
{
    std::cout << "resume after initial pause\n";
    co_yield 1;
    co_yield 2;
    co_yield 3;
}

unique_generator<int> infinite_number_stream(int start = 0)
{
    auto value{ start };

    std::cout << "Infinite number stream:\n";
    for (int i{0};; ++i)
    {
        co_yield value;
        ++value;
    }
}

unique_generator<int> range(int first, int last)
{
    std::cout << "range sequence\n";
    while (first != last)
        co_yield first++;
}

int main()
{
    auto task_generate{ do_work() };

    // () resumes the coroutine
    std::cout << task_generate() << '\n';
    std::cout << task_generate() << '\n';
    std::cout << task_generate() << '\n';
    std::cout << task_generate() << '\n';   // coroutine runs to completion here

    auto task_infinite_sequence{infinite_number_stream(1) };

    for (unsigned int i{0}; i < 10; ++i)
        std::cout << task_infinite_sequence() << '\n';

    auto task_range_sequence{ range(20, 80) };

    for (unsigned int i{0}; i < 30; ++i)
        std::cout << task_range_sequence() << '\n';

    return 0;
}