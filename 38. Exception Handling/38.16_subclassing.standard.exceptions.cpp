//
// Created by Εκλεκτός εν Χριστώ on 6/27/24.
//

/*
 * we can derive from standard exceptions to make our own custom exceptions
 */

#include <iostream>
#include <exception>

class DivideByZero : public std::exception
{
public:
    DivideByZero(int a, int b) noexcept : std::exception{}, m_a{ a }, m_b{ b } {}

    virtual const char* what() const noexcept override
    {
        // another way
        return (std::string("Division by zero detected: ") +
                std::to_string(m_a) + '/' +
                std::to_string(m_b)).c_str();
    }

    int get_a() const { return m_a; }
    int get_b() const { return m_b; }

private:
    int m_a{};
    int m_b{};
};

int divide(int a, int b)
{
    if (b == 0)
        throw DivideByZero{ a, b };

    return a / b;
}

int main()
{
    try
    {
        divide(2, 0);
    }
    catch (std::exception& exception)
    {
        /*  // one way
        // downcasting from exception to dividebyzero to access the non virtual functions of
        // dividebyzero, base reference can't access non virtual functions but virtual functions
        // only, derived ptr_dzero can access non virtual members too
        DivideByZero* ptr_dzero{ dynamic_cast<DivideByZero*>(&exception) };

        // if the cast from base ref to derived ptr is successful, check if the pointer is not
        // a nullptr
        if (ptr_dzero)
        {
            std::cout << exception.what() << ": dividing " << ptr_dzero->get_a();
            std::cout << " by " << ptr_dzero->get_b() << '\n';
        }*/

        std::cout << exception.what() << '\n';
    }

    return 0;
}