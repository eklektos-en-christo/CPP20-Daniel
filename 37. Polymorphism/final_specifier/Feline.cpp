//
// Created by Εκλεκτός εν Χριστώ on 6/13/24.
//

#include "Feline.h"

Feline::Feline(std::string_view fur_style, std::string_view desc)
    : Animal{ desc }, m_fur_style{ fur_style }
{

}