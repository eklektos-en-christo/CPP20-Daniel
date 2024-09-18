//
// Created by Εκλεκτός εν Χριστώ on 3/27/24.
//

/*
 * constructor delegation : constructor using another constructor and avoiding code duplication
 * constructor delegating the responsibility of initialising the members to another constructor
 *
 * do the delegation using initializer list, if the delegation is done inside the body of the
 * constructor, this is gonna create a local object in the constructor
 *
 * we can use delegation in the initializer list only, no other initialization is allowed besides
 * the initializer list
 */

#include <iostream>
#include <string>

class Square
{
private:
    double m_side {};
    std::string m_color {};
    int m_shading {};
    double m_position {};

public:
    explicit Square(double side);
    Square(double side, std::string color, int shading);
    ~Square() = default;
    double surface() const;
};

// this constructor calls the another constructor to initialize the members - delegation
Square::Square(double side) : Square{ side, "black", 4 }
{
    std::cout << "Inside the one param constructor\n";
    m_position = 0.0;
    std::cout << "m_position initialized\nObject creation done!\n";
}

// this constructor constructs the actual object
Square::Square(double side, std::string color, int shading)
    : m_side{ side }, m_color{ color }, m_shading{ shading }
{
    std::cout << "Inside the three param constructor\n";
}

double Square::surface() const
{
    return m_side * m_side;
}

int main()
{
    Square square{ 4 };

    return 0;
}