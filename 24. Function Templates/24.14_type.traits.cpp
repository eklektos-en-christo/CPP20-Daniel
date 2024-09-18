//
// Created by Εκλεκτός εν Χριστώ on 29/02/2024.
//

/*
 * type traits - a mechanism to query information about a templated type at the compile
 * time
 *
 * they work on types, not on values
 *
 * static_assert - mechanism to check something at a compile time, if the expression is
 * true, compilation goes, otherwise compilation stops with an error
 *
 * is_integral_v is an alias for is_integral<type>::value
 */

#include <iostream>
#include <type_traits>      // for type traits

template <typename T>
void is_integral_num(T num)
{
    // compile time check
    static_assert(std::is_integral_v<T>, "You should pass an integer!");
    std::cout << "You passed : " <<  num << '\n';
}

int main()
{
    std::cout << std::boolalpha;
    std::cout << std::is_integral<int>::value << '\n';

    // _v - alias for ::value
    std::cout << std::is_floating_point_v<int> << '\n';
    std::cout << std::is_integral_v<char> << '\n';
    std::cout << std::is_integral_v<long long int> << '\n';

    // compilation fails - type is not an int
    /*is_integral_num(2.2);*/
    is_integral_num(21202);

    auto sum
    {
        []<typename T>(T a, T b)
        {
            // compile time check, possible because of named template parameters
            // enforcing that only floats can be used with this lambda function
            static_assert(std::is_floating_point_v<T>, "Please pass a float");
            return a + b;
        }
    };

    /*std::cout << sum(2.2, 3) << '\n';*/
    std::cout << sum(9.1, 29.6) << '\n';

    return 0;
}