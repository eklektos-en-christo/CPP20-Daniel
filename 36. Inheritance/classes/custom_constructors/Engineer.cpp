//
// Created by Εκλεκτός εν Χριστώ on 5/21/24.
//

#include "Engineer.h"

Engineer::Engineer(std::string_view fullname, int age, std::string_view address, int count)
    : Person{ fullname, age, address }, contract_count{ count }
{
    std::cout << "Engineer received the data\n";
}

// friend has access to the private stuff of Engineer
std::ostream& operator<<(std::ostream& out, const Engineer& engineer)
{
    out << engineer.get_fullname() << ", " << engineer.get_age() << ", ";
    out << engineer.get_address() << ", " << engineer.contract_count;
    return out;
}