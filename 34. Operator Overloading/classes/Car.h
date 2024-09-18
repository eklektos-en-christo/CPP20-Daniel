//
// Created by Εκλεκτός εν Χριστώ on 5/8/24.
//

#ifndef PRACTICE_CAR_H
#define PRACTICE_CAR_H

#include <string>

class Car
{
public:
    Car() = default;
    Car(const std::string& color, double speed);
    ~Car();

    double get_speed() const
    {
        return m_speed;
    }

    std::string get_color() const
    {
        return m_color;
    }

private:
    std::string m_color{};
    double m_speed{};
};

#endif //PRACTICE_CAR_H
