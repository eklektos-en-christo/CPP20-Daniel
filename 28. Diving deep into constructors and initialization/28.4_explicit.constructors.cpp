//
// Created by Εκλεκτός εν Χριστώ on 3/26/24.
//

/*
 * explicit constructors : mark the constructor as explicit if we don't want the constructor to
 * perform implicit conversion of arguments
 */

#include <iostream>
#include <string>

class Square
{
private:
    double m_side{};

public:
    explicit Square(double side);
    ~Square() = default;
    double surface() const;
};

Square::Square(double side) : m_side{ side }
{
}

double Square::surface() const
{
    return m_side * m_side;
}

bool compare_squares(const Square& sq1, const Square& sq2)
{
    return sq1.surface() > sq2.surface();
}

int main()
{
    Square square{ 4 };
    /*std::cout << compare_squares(square, 2) << '\n';*/    // implicit conversion from int to a const Square

    // error - explicit constructor doesn't allow implicit conversions
    /*std::cout << compare_squares(square, 2) << '\n';*/

    // error - implicit conversion from double to const Square
    /*std::cout << compare_squares(square, 2.1) << '\n';*/

    // works - no implicit conversion
    std::cout << compare_squares(square, square) << '\n';

    Square sq1{  };

    return 0;
}