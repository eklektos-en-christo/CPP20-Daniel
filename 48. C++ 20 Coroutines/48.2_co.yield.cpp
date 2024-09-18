//
// Created by Εκλεκτός εν Χριστώ on 9/5/24.
//

/*
 *
 */

#include <iostream>
#include <coroutine>

// our coroutine type, used to return from a coroutine function
struct CoroType
{
    struct promise_type
    {
        int m_value{};
        CoroType get_return_object() { return CoroType(this); }
        std::suspend_always initial_suspend() { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }

        void unhandled_exception() noexcept
        {
            std::rethrow_exception(std::current_exception());
        }

        void return_void() {};      // co_return

        std::suspend_always yield_value(int value)      // co_yield
        {
            m_value = value;
            return {};
        }
    };

    CoroType(promise_type* p)
            : m_handle(std::coroutine_handle<promise_type>::from_promise(*p))
    {
    }

    ~CoroType()
    {
        m_handle.destroy();
    }

    std::coroutine_handle<promise_type> m_handle;
};

CoroType do_work()
{
    std::cout << "starting after initial pause\n";
    co_yield 1;
    co_yield 2;
    co_yield 3;
}

int main()
{
    // coroutine pauses here - initial pause
    auto task{ do_work() };

    task.m_handle.resume();
    std::cout << task.m_handle.promise().m_value << '\n';

    task.m_handle.resume();
    std::cout << task.m_handle.promise().m_value << '\n';

    task.m_handle.resume();
    std::cout << task.m_handle.promise().m_value << '\n';

    std::cout << std::boolalpha << task.m_handle.done() << '\n';

    // coroutine ends after this resumption
    task.m_handle.resume();

    std::cout << task.m_handle.done() << '\n';

    return 0;
}