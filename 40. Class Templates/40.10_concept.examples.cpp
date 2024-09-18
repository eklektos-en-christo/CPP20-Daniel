//
// Created by Εκλεκτός εν Χριστώ on 7/11/24.
//

/*
 *
 */

#include <iostream>
#include <concepts>
#include <vector>

// specifying a custom concept
// enforces that type T should have an ostream operator for printing
template <typename T>
concept OutputStreamable = requires(std::ostream& o, T d)
{
    o << d;
};

template <typename T> requires OutputStreamable<T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v)
{
    for (auto i : v)
        out << i << ' ';

    return out;
}

struct Point
{
    double m_x{};
    double m_y{};

    Point() = default;
    Point(double x, double y) : m_x{x}, m_y{y} {}

    friend std::ostream& operator<<(std::ostream& out, Point& operand)
    {
        out << '(' << operand.m_x << ", " << operand.m_y << ") ";
        return out;
    }
};

// a new concept
// type should be a number, not boolean nor character
template <typename T>
concept Number = (std::integral<T> || std::floating_point<T>)
                 && (!std::same_as<T, char> && std::same_as<T, bool>);

// constraining the template function to accept numbers only
template <Number T, Number U>
auto add(T x, U y)
{
    return x + y;
}

int main()
{
    std::vector<int> numbers{ 1, 2, 3, 4, 5 };
    std::cout << numbers << '\n';

    std::vector<Point> points{ {1.1, 2.2}, {2.6, 8.3} };
    std::cout << points << '\n';

    // constraints not satisfied
    /*std::cout << add("a", "b") << '\n';*/
    /*std::cout << add('a', 'b') << '\n';*/

    return 0;
}