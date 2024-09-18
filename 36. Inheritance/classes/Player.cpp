//
// Created by Εκλεκτός εν Χριστώ on 5/19/24.
//

#include "Player.h"

std::ostream& operator<<(std::ostream& out, const Player& player)
{
    out << player.get_fname() << ' ' << player.get_lname();
    out << ", Game : " << player.m_game;
    return out;
}

Player::Player(std::string_view game) : m_game{ game }
{
}