//
// Created by Εκλεκτός εν Χριστώ on 5/14/24.
//

/*
 *
 */

#include <iostream>
#include <cmath>

class Point
{
public:
    Point(int x, int y) : m_x{x}, m_y{y}{}
    bool operator==(const Point& right) const { return length() == right.length(); }

    // one or both of points might be incomparable if they're out of bounds - partial
    // ordering
    std::partial_ordering operator<=>(const Point& right) const
    {
        // only compare two points if they're comparable, within the bounds
        if (is_within_bounds(*this) && is_within_bounds(right))
        {
            if (length() > right.length())
                return std::partial_ordering::greater;
            else if (length() < right.length())
                return std::partial_ordering::less;
            else
                return std::partial_ordering::equivalent;
        }

        // if one or both of them are incomparable
        return std::partial_ordering::unordered;
    }

private:
    int m_x{};
    int m_y{};

    double length() const
    {
        return std::sqrt(pow(m_x - 0, 2) + pow(m_y - 0, 2) * 1.0);
    }

    bool is_within_bounds(const Point& p) const
    {
        if ((std::abs(p.m_x) < 100) && (std::abs(p.m_y) < 100))
            return true;
        return false;
    }
};

int main()
{
    Point p1{ 11, 98 };
    Point p2{ 88, 72 };

    std::cout << (p1 == p2) << '\n';
    std::cout << (p1 != p2) << '\n';
    std::cout << (p1 > p2) << '\n';
    std::cout << (p1 < p2) << '\n';

    return 0;
}