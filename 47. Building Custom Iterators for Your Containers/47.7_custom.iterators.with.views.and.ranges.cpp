//
// Created by Εκλεκτός εν Χριστώ on 8/29/24.
//

/*
 *
 */

#include <iostream>
#include "classes/boxcontainer.h"
#include <ranges>
#include <algorithm>

// it is a function template
void print(auto view)
{
    for (auto i : view)
        std::cout << i << ' ';
    std::cout << '\n';
}

struct Student
{
    friend std::ostream& operator<<(std::ostream& out, const Student& s)
    {
        out << '[' << s.m_name << ", " << s.m_age << ']';
        return out;
    }

    auto operator<=>(const Student& s) const = default;
    std::string m_name{};
    unsigned int m_age{};
};

int main()
{
    BoxContainer<int> box1;
    box1.add(2);
    box1.add(1);
    box1.add(3);
    box1.add(4);
    box1.add(9);
    box1.add(5);
    box1.add(8);
    box1.add(7);

    auto f_pred{ [](int i){ return i % 2 == 0; } };

    // using a view with our custom container, this works because container provides iterators
    std::ranges::filter_view f_view{ std::ranges::filter_view(box1, f_pred) };
    print(f_view);

    print(std::ranges::transform_view(box1, [](int i){ return i * 10; }));
    print(box1);

    print(std::ranges::take_view(box1, 4));
    print(std::ranges::take_while_view(box1, [](int i){ return (i % 2 == 0); }));

    print(std::ranges::drop_view(box1, 3));

    BoxContainer<Student> classroom;
    classroom.add(Student{ "Michael", 22 });
    classroom.add(Student{ "Shayla", 32 });
    classroom.add(Student{ "Dan", 41 });
    classroom.add(Student{ "Elliot", 39 });

    for (auto& student : classroom)
        std::cout << student << ' ';
    std::cout << '\n';

    // sort by age
    std::ranges::sort(classroom, std::less<>{}, &Student::m_age);

    for (auto& student : classroom)
        std::cout << student << ' ';
    std::cout << '\n';

    auto less_than_40{ classroom | std::views::take_while([](const Student& s){ return s.m_age < 40; })};
    print(less_than_40);

    return 0;
}