//
// Created by Εκλεκτός εν Χριστώ on 5/19/24.
//

#include "Player.h"

std::ostream& operator<<(std::ostream& out, const Player& player)
{
    out << player.m_fname << ' ' << player.m_lname;
    out << ", Game : " << player.m_game;
    return out;
}

Player::Player(std::string_view game, std::string_view fname, std::string_view lname)
    : m_game{ game }
{
    m_fname = fname;
    m_lname = lname;
}