//
// Created by Εκλεκτός εν Χριστώ on 16/12/2023.
//

/*
 * short circuit evaluation: in case of AND operation, if one operand is zero, the
 * result is zero, we can put the false operand first to save the computation power
 *
 * in case of OR operation, if one operand is 1, the result is 1, we can save the
 * computing power by putting the true operand first in the condition
 */

#include <iostream>

bool a()
{
    std::cout << "a executing\n";
    return true;
};

bool b()
{
    std::cout << "b executing\n";
    return false;
};

bool c()
{
    std::cout << "c executing\n";
    return false;
};

bool x()
{
    std::cout << "x executing\n";
    return true;
};

bool y()
{
    std::cout << "y executing\n";
    return false;
};

bool z()
{
    std::cout << "z executing\n";
    return false;
};

int main()
{
    // short circuiting - a() && b() is false, so whole is false, c() is not evaluated
    if (a() && b() && c())
        std::cout << "AND is successful\n";

    // x() || y() is true, so whole is true, y() and z() are not evaluated
    if (x() || y() || z())
        std::cout << "OR is successful\n";

    return 0;
}