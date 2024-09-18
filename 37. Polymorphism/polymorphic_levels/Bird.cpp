//
// Created by Εκλεκτός εν Χριστώ on 6/13/24.
//

#include "Bird.h"

Bird::Bird(std::string_view wing_color, std::string_view desc)
    : Animal{ desc }, m_wing_color{ wing_color }
{

}