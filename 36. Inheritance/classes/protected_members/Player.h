//
// Created by Εκλεκτός εν Χριστώ on 5/19/24.
//

#ifndef PRACTICE_PLAYER_H
#define PRACTICE_PLAYER_H

#include "Person.h"
#include <string>
#include <string_view>
#include <iostream>

// player also has the Person part - public inheritance,
// protected stuff from Person is accessible in this class
class Player : public Person
{
    friend std::ostream& operator<<(std::ostream& out, const Player& player);

public:
    Player() = default;
    explicit Player(std::string_view game, std::string_view fname, std::string_view lname);
    ~Player() = default;

private:
    std::string m_game{};
};

#endif //PRACTICE_PLAYER_H
