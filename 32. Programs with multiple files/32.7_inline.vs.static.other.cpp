//
// Created by Εκλεκτός εν Χριστώ on 4/18/24.
//

#include <iostream>

inline int age{ 2 };

inline void print_age1()
{
    std::cout << "inline2 age : " << &age << '\n';
}

void print_age_inline2()
{
    print_age1();
}

namespace
{
    int data{ 3 };
    void print_data()
    {
        std::cout << "namespace2 : " << &data << '\n';
    }
}

static int static1{ 20 };

void namespace_print1()
{
    print_data();
    std::cout << "static2 : " << &static1 << '\n';
}