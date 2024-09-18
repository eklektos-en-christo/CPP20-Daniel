//
// Created by Εκλεκτός εν Χριστώ on 4/4/24.
//

/*
 * we can also define the static inline constants in the class to use them in every object,
 * like a PI
 */

#include <iostream>

class Cylinder
{
public:
    Cylinder() = default;
    Cylinder(double radius, double height)
        : m_radius{ radius }, m_height{ height }
    {
    }

    double volume() const { return PI * m_radius * m_radius * m_height; }

private:
    double m_radius{};
    double m_height{};
    static inline const double PI{ 3.14 };
};

int main()
{
    Cylinder c1{ 2.0, 5.0 };
    std::cout << c1.volume() << '\n';

    return 0;
}