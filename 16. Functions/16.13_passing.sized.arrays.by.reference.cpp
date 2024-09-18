//
// Created by Εκλεκτός εν Χριστώ on 19/01/2024.
//

/*
 * passing a sized array by reference : compiler will enforce the size of the array to
 * be exact as it is specified in the parameter, if argument is not same as the size of
 * the parameter array, error
 * this is the preferred method of passing fixed arrays without making their copies, if
 * we use the pointer instead of reference, we can't deduce the size of the array
 * through pointer, we then have to pass the size of the array separately in a parameter,
 * in this case reference syntax works well
 */

#include <iostream>

// reference is going to preserve the size of the array A, we can deduce it using
// std::size, size is fixed, so argument's size should also be fixed and same
// no copies of array A will be made
double sum(const double (&A)[5])
{
    double sum{};

    for (std::size_t i{0}; i < std::size(A); ++i)
    {
        sum += A[i];
    }

    return sum;
}

int main()
{
    double A[]{ 1.1, 2.8, 3.4, 4.2, 5.7 };

    std::cout << sum(A) << '\n';

    return 0;
}