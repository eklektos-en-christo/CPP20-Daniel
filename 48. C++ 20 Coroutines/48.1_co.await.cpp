//
// Created by Εκλεκτός εν Χριστώ on 9/4/24.
//

/*
 * C++20 coroutines don't provide classes but infrastructure, and we have to build on that
 * infrastructure to make our own coroutines
 */

#include <iostream>
#include <coroutine>

// our coroutine type, used to return from a coroutine function
struct CoroType
{
    struct promise_type
    {
        CoroType get_return_object() { return CoroType(this); }
        std::suspend_always initial_suspend() { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }
        void unhandled_exception() noexcept
        {
            std::rethrow_exception(std::current_exception());
        }
        void return_void() {};
    };

    CoroType(promise_type* p)
        : m_handle(std::coroutine_handle<promise_type>::from_promise(*p))
    {
    }

    ~CoroType()
    {
        std::cout << "Handle destroyed\n";
        m_handle.destroy();
    }

    std::coroutine_handle<promise_type> m_handle;
};

// a coroutine, returns a coroutine type and contains coroutine operator(s)
CoroType do_work()
{
    std::cout << "first thing\n";
    co_await std::suspend_always{};

    std::cout << "second thing\n";
    co_await std::suspend_always{};

    std::cout << "third thing\n";
}

int main()
{
    // coroutine pauses when first called
    auto task{ do_work() };

    // resume the coroutine, pauses at first co_await statement
    task.m_handle();

    // check if coroutine is done executing
    std::cout << std::boolalpha << task.m_handle.done() << '\n';

    // resume again, pauses at second co_await statement
    task.m_handle.resume();

    // resume again
    task.m_handle.resume();

    // coroutine is done executing
    std::cout << std::boolalpha << task.m_handle.done() << '\n';

    // error : can't resume a coroutine that has completed its execution
    /*task.m_handle.resume();*/

    return 0;

    // coroutine handle is destroyed here
}