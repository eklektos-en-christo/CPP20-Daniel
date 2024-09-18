//
// Created by Εκλεκτός εν Χριστώ on 7/8/24.
//

/*
 * friend classes can be non template or template
 * friend functions can be non template or template
 *
 *
 */

#include <iostream>

// template class declaration
// forward declaration for the template function declaration to work
template <class T>
class TemplateClass;

// template function
template <typename T>
void some_func(TemplateClass<T>);

// template class
template <class T>
class TemplateClass
{
    // template function as a friend of the template class
    // <T> is necessary to tell the compiler that this is a
    // template function and not a non-template function
    friend void some_func<T>(TemplateClass<T> param);

public:
    explicit TemplateClass() = default;
    void set_up(T param) { m_var = param; }
    void do_something(const T a, T b) { std::cout << a << ", " << b << '\n'; }

private:
    T m_var{};
};

template <typename T>
void some_func(TemplateClass<T> param)
{
    std::cout << "Friend accessing the private stuff of TemplateClass: ";
    std::cout << param.m_var << '\n';
}

int main()
{
    TemplateClass<int> tc1;
    tc1.set_up(2);
    some_func(tc1);         // friend can access the private data

    TemplateClass<double> tc2;
    tc2.set_up(8.888);
    some_func(tc2);         // friend can access the private data

    return 0;
}