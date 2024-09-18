//
// Created by Εκλεκτός εν Χριστώ on 9/7/24.
//

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

        // use when co_return returns a value
        /*void return_value(int value)                    // for passing an operand to co_return operator
        {
            m_value = value;
        }*/

        // use when no need to return a value
        void return_void() {};                          // co_return

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
    std::cout << "resume after initial pause" << '\n';
    co_yield 1;
    co_yield 2;
    co_yield 3;
    co_return;     // returns nothing
}

int main()
{
    auto task{ do_work() };

    task.m_handle.resume();
    std::cout << task.m_handle.promise().m_value << '\n';

    task.m_handle.resume();
    std::cout << task.m_handle.promise().m_value << '\n';

    task.m_handle.resume();
    std::cout << task.m_handle.promise().m_value << '\n';

    task.m_handle.resume();
    std::cout << std::boolalpha << task.m_handle.done() << '\n';

    return 0;
}