//
// Created by Εκλεκτός εν Χριστώ on 5/21/24.
//

#include "Engineer.h"

Engineer::Engineer(std::string_view fullname, int age, std::string_view address, int count)
    : Person{ fullname, age, address }, contract_count{ count }
{
    std::cout << "Engineer received the data\n";
}

// this is gonna work but Person will be a temp. object and base Person will be copying from
// from that temp Person to initialize itself, to avoid copying, there is a fix below
/*Engineer::Engineer(const Engineer& src_engg)
    : Person{ src_engg.m_fullname, src_engg.m_age, src_engg.get_address() },
      contract_count{ src_engg.contract_count }
{
    std::cout << "Custom copy constructor called for Engineer\n";
}*/

// works - src_engg has a base part, that will be used to copy to the base Person
// the Engineer part will be stripped off in this process, no new copies of Person are made here
// to copy to the base Person, infact the base copy constructor is called, which is what we want
Engineer::Engineer(const Engineer& src_engg)
    : Person{ src_engg },                       /*derived Engineer is sliced off when copied*/
      contract_count{ src_engg.contract_count }
{
    std::cout << "Custom copy constructor called for Engineer\n";
}

// friend has access to the private stuff of Engineer
std::ostream& operator<<(std::ostream& out, const Engineer& engineer)
{
    out << engineer.get_fullname() << ", " << engineer.get_age() << ", ";
    out << engineer.get_address() << ", " << engineer.contract_count;
    return out;
}