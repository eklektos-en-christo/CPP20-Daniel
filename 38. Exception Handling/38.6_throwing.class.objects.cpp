//
// Created by Εκλεκτός εν Χριστώ on 6/24/24.
//

/*
 * when throwing custom type objects:
 * type must be copyable and public,
 * the object is copied to the catch block and the copied from object dies
 *
 * catch parameter should be a reference to avoid copies when parameter is used inside the catch
 *
 * always use what() member in the type to tell the actual problem when an exception is thrown
 */

#include <iostream>
#include <string_view>
#include <string>

class SomethingWrong
{
public:
    SomethingWrong() = default;
    SomethingWrong(std::string_view message)
        : m_message{ message }
    {
    }

    // necessary for exceptions
    SomethingWrong(const SomethingWrong& src)
        : m_message{ src.m_message }
    {
        std::cout << "Copy constructor called: SomethingWrong\n";
    }

    ~SomethingWrong() = default;

    std::string_view what() const { return m_message; }

private:
    std::string m_message{};
};

void do_something(std::size_t i)
{
    if (i == 5)
        throw SomethingWrong("i is 2");

    // at 5, this will be skipped and catch block in main() is entered
    std::cout << "Iteration: " << i << '\n';
}

int main()
{
    for (std::size_t i{0}; i < 10; ++i)
    {
        try
        {
            do_something(i);
        }       // & to avoid copies
        catch (SomethingWrong& sw)
        {
            std::cout << "Exception: " << sw.what() << '\n';
        }
    }

    return 0;
}