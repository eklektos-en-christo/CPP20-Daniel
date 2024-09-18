//
// Created by Εκλεκτός εν Χριστώ on 14/02/2024.
//

/*
 * when deducing from a reference, the reference is removed, only the type is deduced
 *
 * to deduce a reference from a reference, use & after the auto keyword
 *
 * reference auto type deduction will conserve the constness of the reference, if
 * the input is a const reference then the deduced reference will be a const
 * reference also - auto& var_name{ input_ref }
 *
 * non reference auto type deduction doesn't keep the constness - auto var_name{ref}
 */

#include <iostream>

int main()
{
    double variable{ 199.2 };

    // x is a different variable, 199.2 will be copied to x of type double
    auto x{ variable };

    std::cout << &variable << '\n';
    std::cout << &x << '\n';

    // ref_x is copied to y, y is not deduced as a reference but a double only
    // y is not ref_x, it is a different variable
    double& ref_x{ x };
    auto y{ ref_x };
    ++y;

    std::cout << ref_x << '\n';
    std::cout << y << '\n';

    // to deduce the reference from a reference use auto&
    auto& z{ ref_x };
    ++z;

    std::cout << ref_x << '\n';
    std::cout << z << '\n';

    // auto& - preserves the constness
    const double var_const{ 182.3 };
    auto& ref_var_const{ var_const };

    // can't modify the var_const
    /*++ref_var_const;*/

    return 0;
}