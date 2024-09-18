//
// Created by Εκλεκτός εν Χριστώ on 4/1/24.
//

/*
 * aggregates - special containers in C++
 *
 * list initializer constructor - takes the data from the initializer and put that in
 * the aggregate compound type
 *
 * to customize the initializer constructor, we can use std::initializer_list in the
 * constructor's parameter list
 *
 * simply - we can use initializer_list in the constructor to take the arguments in
 * a {} from the main and then use that initializer_list to initialize the member
 * variable of the class
 */

#include <iostream>
#include <initializer_list>
#include <cassert>          // for runtime check

struct Point
{
public:
    Point(std::initializer_list<double> list)
    {
        std::cout << "std::initializer_list constructor called\n";

        // forcing to pass 2 arguments only
        assert(list.size() == 2);

        // taking the elements from the list and initializing the memebers
        x = *(list.begin());            // dereference the ptr to get the data
        y = *(list.begin() + 1);        // ptr arithmetic for next element
    }

    void print_point() const
    {
        std::cout << "(" << x << ", " << y << ")\n";
    }

private:
    double x{};
    double y{};
};

int main()
{
    // using the {} to initialize the x and y in Point - std::initializer_list constructor used
    // behind the scenes by the compiler
    Point p1{ 2.6, 8.9, /*22.1*/ };     // we can use more than the required elements, put the assert so commented out the 3rd argument
    p1.print_point();

    return 0;
}