//
// Created by Εκλεκτός εν Χριστώ on 5/21/24.
//

#include "Nurse.h"

std::ostream& operator<<(std::ostream& out, const Nurse& nurse)
{
    out << nurse.get_fullname() << ", " << nurse.m_age << ", " << nurse.get_address();
    out << ", " << nurse.cert_id;
    return out;
}