//
// Created by Εκλεκτός εν Χριστώ on 6/6/24.
//

/*
 * we can have similar names in both base and derived classes, names in derived will
 * override the names in base, in function calls the derived functions will be called
 * instead of the base, when base calls its function, it won't call the derived's
 * functions
 *
 * we can call the base version from the derived object also by using:
 *      derived_object.base_class::func_name();
 */

#include <iostream>

class Parent
{
protected:
    int age{ 0 };

public:
    void print_age() { std::cout << "Parent: " << age << '\n'; }
};

class Child : public Parent
{
public:
    // this use the Child's age, Parent's age is overridden
    void print_age()
    {
        std::cout << "Child: " << age << '\n';

        // we can use parent's age too in derived using :: if the data is accessible
        std::cout << "Parent's age too: " << Parent::age << '\n';
    }

protected:
    int age{ 1 };
};

int main()
{
    Child c1;
    c1.print_age();             // derived object calls its own function

    c1.Parent::print_age();     // derived object can also call the base function

    return 0;
}