//
// Created by Εκλεκτός εν Χριστώ on 5/19/24.
//

#include "Player.h"
#include "Person.h"

std::ostream& operator<<(std::ostream& out, const Player& player)
{
    out << player.get_fullname() << ' ' << player.get_age() << ", ";
    out << player.get_address();
    return out;
}