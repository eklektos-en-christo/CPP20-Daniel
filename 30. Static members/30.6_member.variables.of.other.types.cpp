//
// Created by Εκλεκτός εν Χριστώ on 4/6/24.
//

#include <iostream>

class Integer
{
public:
    explicit Integer(int value) : inner_int{value} {}
    Integer() = default;
    ~Integer() = default;
    int get_value() const { return inner_int; }
    void set_value(int value) { inner_int = value; }

private:
    int inner_int{0};
};

class Point
{
    double m_x{};
    double m_y{};

public:
    // possiblities with member variables which are of another type
    Integer i1{0};
    const Integer i2{2};
    static inline Integer i3{3};
    static inline const Integer i4{4};

    Integer* p_i5{nullptr};
    static Integer i6;
    static const Integer i7;

    // initialising the ptr member in the constructor
    Point(double x, double y) : m_x{x}, m_y{y}, p_i5{ new Integer{5} }
    {
    }

};

int main()
{
    Point p{ 2.1, 3.6 };
    std::cout << p.i1.get_value() << '\n';
    std::cout << p.p_i5->get_value() << '\n';

    return 0;
}