//
// Created by Εκλεκτός εν Χριστώ on 6/26/24.
//

/*
 * we can throw an std::exception or its derived classes according to the error we
 * have in the program
 */

#include <iostream>
#include <exception>
#include <string>
#include <string_view>

class Students
{
public:
    Students(std::string_view s1, std::string_view s2, std::string_view s3,
             std::string_view s4, std::string_view s5)
    {
        m_names[0] = s1;
        m_names[1] = s2;
        m_names[2] = s3;
        m_names[3] = s4;
        m_names[4] = s5;
    }

    ~Students() = default;

    std::string_view get_student(std::size_t index)
    {
        const std::string message{ "Index out of range, valid range: 0-4" };

        if (index < 0 || index > 4)
            throw std::out_of_range(message);   // throwing a standard exception
        return m_names[index];
    }

private:
    std::string m_names[5]{};
};

int main()
{
    Students students{ "John", "Luke", "David", "Paul", "Matthew" };

    std::cout << students.get_student(4) << '\n';

    try
    {
        std::cout << students.get_student(-2) << '\n';
    }
    // base class reference used as parameter - polymorphism
    catch (std::exception& exception)
    {
        std::cout << exception.what() << '\n';
    }

    return 0;
}