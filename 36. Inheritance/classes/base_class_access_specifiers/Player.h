//
// Created by Εκλεκτός εν Χριστώ on 5/19/24.
//

#ifndef PRACTICE_PLAYER_H
#define PRACTICE_PLAYER_H

#include "Person.h"
#include <string>
#include <string_view>
#include <iostream>

// public inheritance - 1
// anything from Person stays the same in Player,
// public as public and protected as
// protected and private as private
class Player : public Person
{
    friend std::ostream& operator<<(std::ostream& out, const Player& player);

public:
    Player() = default;
    ~Player() = default;

    // checking the access of base class members
    void play()
    {
        m_fullname = "Somebody played with the name";   // public remains public
        m_age = -2;                                     // protected remains protected
        //m_address = "Address is changed";               // private remains private, error
    }

private:
    int m_career_start_year{};
    double m_salary{};
    int m_health_factor{};
};

#endif //PRACTICE_PLAYER_H
