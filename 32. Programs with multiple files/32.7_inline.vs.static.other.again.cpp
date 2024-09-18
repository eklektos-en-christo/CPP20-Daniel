//
// Created by Εκλεκτός εν Χριστώ on 4/18/24.
//

#include <iostream>

inline int age{ 2 };

inline void print_age2()
{
    std::cout << "inline1 age : " << &age << '\n';
}

void print_age_inline1()
{
    print_age2();
}

namespace
{
    int data{ 3 };
    void print_data()
    {
        std::cout << "namespace1 : " << &data << '\n';
    }
}

static int static1{ 20 };

void namespace_print2()
{
    print_data();
    std::cout << "static1 : " << &static1 << '\n';
}