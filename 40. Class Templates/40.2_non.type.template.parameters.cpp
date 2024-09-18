//
// Created by Εκλεκτός εν Χριστώ on 7/5/24.
//

/*
 * non type template parameters : parameters in the template declaration other than the
 * template type, they define a value and we can use that value in our class or member
 * functions
 *
 * template <typename T>        - template type param
 * template <typename T, int my_type> - non type template param my_type
 *
 * we can also use our template parameters e.g. T as non type template parameters, this limits
 * the non type template paramters to be of the same type as the template parameters
 *
 * template <typename T, T value>   - T as non type template param, value is of same type as
 * the template type T is. value should be of same type as T when template argument is
 * passed
 *
 * every time a non type template param's value is changed, a new instance will be generated
 * or we can pass the same data to ctors, instead to non type template params
 */

#include "nontype_template_params/BoxContainer.h"

// template type T as a non template type parameter - threshold
template <typename T, T threshold>
class Point
{
public:
    Point(T x=0, T y=0);

private:
    T m_x{};
    T m_y{};
};

template <typename T, T threshold>
Point<T, threshold>::Point(T x, T y)
    : m_x{ x }, m_y{ y }
{
}

int main()
{
    // 2nd param passed as non type template param
    BoxContainer<int, 10> int_box;

    int_box.add(2);
    int_box.add(3);
    int_box.add(33);
    int_box.add(9);
    int_box.add(7);

    std::cout << int_box << '\n';

    Point<double, 6.2> point;

    return 0;
}