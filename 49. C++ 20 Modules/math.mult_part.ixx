//
// Created by Εκλεκτός εν Χριστώ on 9/18/24.
//

// export this module as a partition of the math module
// this partition can only be accessed via math module
export module math:multiply;

import <iostream>;

export void multiply(int a, int b)
{
    std::cout << a * b << '\n';
}
