//
// Created by Εκλεκτός εν Χριστώ on 23/02/2024.
//

/*
 *
 */

#include <iostream>

// overloads with different pointer type of parameters
double max(const double* numbers, std::size_t count)
{
    double max{0};

    for (std::size_t i{0}; i < count; ++i)
    {
        if (numbers[i] > max)
            max = numbers[i];
    }

    return max;
}

// overload of previous function max
int max(const int* numbers, std::size_t count)
{
    int max{0};

    for (std::size_t i{0}; i < count; ++i)
    {
        if (numbers[i] > max)
            max = numbers[i];
    }

    return max;
}

// compiler knows that * and [] are same - error
/*int max(const int numbers[], std::size_t count)
{
    int max{0};

    for (std::size_t i{0}; i < count; ++i)
    {
        if (numbers[i] > max)
            max = numbers[i];
    }

    return max;
}*/

int main()
{
    int ints[]{ 12, 20, 33, 10 };
    double doubles[]{ 2.2, 1.9, 8.1, 6.4 };

    std::cout << max(ints, std::size(ints)) << '\n';
    std::cout << max(doubles, std::size(doubles)) << '\n';

    return 0;
}