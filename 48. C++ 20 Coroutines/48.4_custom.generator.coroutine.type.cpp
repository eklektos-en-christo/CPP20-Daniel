//
// Created by Εκλεκτός εν Χριστώ on 9/7/24.
//

/*
 *
 */

#include <iostream>
#include <coroutine>
#include <cassert>

template <typename T>
struct Generator
{
    struct promise_type
    {
        T m_value{};
        Generator get_return_object() { return Generator(this); }
        std::suspend_always initial_suspend() { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }

        void unhandled_exception() noexcept
        {
            std::rethrow_exception(std::current_exception());
        }

        // use when no need to return a value
        void return_void() { std::cout << "co_return called\n"; };                          // co_return

        std::suspend_always yield_value(T value)      // co_yield
        {
            m_value = value;
            return {};
        }
    };

    Generator(promise_type* p)
            : m_handle(std::coroutine_handle<promise_type>::from_promise(*p))
    {
    }

    ~Generator()
    {
        m_handle.destroy();
    }

    // to resume the coroutine
    T operator()()
    {
        assert(m_handle != nullptr);    // validate the handle
        m_handle.resume();
        return m_handle.promise().m_value;  // return the value to the caller
    }

    std::coroutine_handle<promise_type> m_handle;
};

Generator<int> do_work()
{
    std::cout << "resume after initial pause\n";
    co_yield 1;
    co_yield 2;
    co_yield 3;
}

Generator<int> infinite_number_stream(int start = 0)
{
    auto value{ start };

    std::cout << "Infinite number stream:\n";
    for (int i{0};; ++i)
    {
        co_yield value;
        ++value;
    }
}

Generator<int> range(int first, int last)
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
    std::cout << std::boolalpha << task_generate.m_handle.done() << '\n';

    auto task_infinite_sequence{infinite_number_stream(1) };

    for (unsigned int i{0}; i < 10; ++i)
        std::cout << task_infinite_sequence() << '\n';

    auto task_range_sequence{ range(20, 80) };

    for (unsigned int i{0}; i < 30; ++i)
        std::cout << task_range_sequence() << '\n';

    return 0;
}