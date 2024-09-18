//
// Created by Εκλεκτός εν Χριστώ on 6/27/24.
//

#include "classes/BoxContainer.h"

int main()
{
    // init. capacity
    BoxContainer box1{ 3 };

    box1.add(2);
    box1.add(5);
    box1.add(3);
    box1.add(5);
    box1.add(4);
    box1.add(5);
    box1.add(6);

    BoxContainer box2;

    box2.add(9);
    box2.add(10);
    box2.add(11);

    box2 += box1;

    std::cout << box2 << '\n';

    box2 = box1;

    std::cout << box2 << '\n';

    std::cout << (box1 + box2) << '\n';

    return 0;
}