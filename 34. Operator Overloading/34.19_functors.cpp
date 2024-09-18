//
// Created by Εκλεκτός εν Χριστώ on 5/8/24.
//

/*
 * functors : are objects, they overload the () operator, by this we can call the member from
 * the object like a function call, objects work like a function call
 *
 * functors are useful in callbacks
 */

#include <iostream>

class Print
{
public:
    void operator()(const std::string& name)
    {
        std::cout << "Name : " << name << '\n';
    }

    std::string operator()(const std::string& last_name, const std::string& first_name)
    {
        return last_name + " " + first_name;
    }
};

void do_something(Print& printer)
{
    printer("Draper");
}

int main()
{
    Print p1;
    p1("leon");
    std::cout << p1("Mr.", "Robot") << '\n';

    do_something(p1);

    return 0;
}