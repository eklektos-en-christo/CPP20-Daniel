//
// Created by Εκλεκτός εν Χριστώ on 3/6/24.
//

/*
 * we can combine concepts using && and ||
 */

#include <iostream>
#include <concepts>

template <typename T>
concept int_only = requires (T t)
{
    requires sizeof(T) == 4;
};

template <typename T>    // combining the concepts using && and ||
T add(T a, T b) requires std::integral<T> || std::floating_point<T> && int_only<T>
{
    return a + b;
}

int main()
{
    // either integral or floats can be passed
    add(2.2f, 2.9f);
    add('a', 'b');

    return 0;
}