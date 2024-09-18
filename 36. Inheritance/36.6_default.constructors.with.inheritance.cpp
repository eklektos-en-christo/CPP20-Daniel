//
// Created by Εκλεκτός εν Χριστώ on 5/29/24.
//

/*
 * in derived, the base stuff is built first, then the derived is built - initialization
 * constructor helps in initializing the base class
 *
 * there should be a default constructor in the classes, if derived doesn't explicitly call the
 * base constructor to initialize the base, then default constructor helps in building the
 * base class first
 */

#include <iostream>

class Person
{
public:
    Person() { std::cout << "BUILDING PERSON\n"; }
};

class Engineer : public Person
{
public:
    Engineer() { std::cout << "BUILDING ENGINEER\n"; }
};

class CivilEngineer : public Engineer
{
public:
    CivilEngineer() { std::cout << "BUILDING CIVIL ENGINEER\n"; }
};

int main()
{
    // most base is built first then its derived then its derived
    CivilEngineer c1;

    return 0;
}