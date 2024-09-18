//
// Created by Εκλεκτός εν Χριστώ on 5/21/24.
//

#include "Engineer.h"

// friend has access to the private stuff of Engineer
std::ostream& operator<<(std::ostream& out, const Engineer& engineer)
{
    out << engineer.get_fullname() << ", " << engineer.get_age() << ", ";
    out << engineer.get_address() << ", " << engineer.contract_count;
    return out;
}