//
// Created by Εκλεκτός εν Χριστώ on 7/15/24.
//

/*
 * by default a lambda inside class won't have access to this pointer of the class, it can have
 * this ptr by capturing it inside the [] using this keyword or when everything is captured by value= or
 * reference, this will also be captured
 */

#include <iostream>

class Item
{
public:
    Item(int a, int b) : m_a{a}, m_b{b} {}


    void print_members()
    {
        // this ptr established the connection between lambda and Item class
        auto lambda{ [this](){
            std::cout << m_a << " " << m_b << '\n';
        }};

        lambda();
    }

private:
    int m_a{};
    int m_b{};
};

int main()
{
    Item item1{ 2, 2 };

    item1.print_members();

    return 0;
}