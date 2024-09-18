//
// Created by Εκλεκτός εν Χριστώ on 3/4/24.
//

/*
 * custom concepts :
 *
 * syntax :             template <typename T>
 *                      concept concept_name = type_trait<T>;   // enforce the T to be only integral
 *
 *
 *                      // if type_trait evaluates to false then concept will not be satisfied - error
 *
 * syntax when we have multiple statements :
 *
 *                      template <typename T>
 *                      concept concept_name = requires(T a, T b..)
 *                      {
 *                          a * b;                 // enforces that parameters should be multipliable
 *                      }                          // otherwise error, and this doesn't check the value of a and b
 *                                                 // if we pass two strings, then there will be an error
 *
 * syntax :             template <typename T>
 *                      concept concept_name = requires(T a)
 *                      {
 *                          ++a;
 *                          --a;
 *                          a += 1;               // incrementable and decrementable constraints on template parameters
 *                      }
 *
 * usage of concepts after declaring them :
 *
 *                      // syntax 1
 *                      template <typename T>
 *                      requires created_concept<T>     // using our own concept, <T> is necessary
 *                      return_type func_name(T a, T b)
 *                      {
 *                          body
 *                      }
 *
 *
 *                      // syntax 2
 *                      template <created_concept T>
 *                      .......func_name....body
 *
 *
 *                      // syntax 3
 *                      auto func_name(created_concept auto a, created_concept auto b)
 *                      ......body...
 */

#include <iostream>
#include <concepts>
#include <type_traits>

// syntax - declaring using type_traits
template <typename T>
concept doubles_only = std::is_floating_point_v<T>;

// syntax - declaring using requires
template <typename T>
concept multipliable = requires(T a, T b)
{
    a * b;
    --a;
    ++a;
    a += 1;
};

// syntax 1 using concept in place of typename
/*template <doubles_only T>
T sum_doubles(T a, T b)
{
    return a + b;
}*/

// syntax 2 using requires clause
/*template <typename T>
requires doubles_only<T>
T sum_doubles(T a, T b)
{
    return a + b;
}*/

// syntax 3 using auto
doubles_only auto sum_doubles(doubles_only auto a, doubles_only auto b)
{
    return a + b;
}

template <multipliable T, multipliable P>
auto multiply(T a, P b)
{
    ++a; ++b;
    return a * b;       // will check for valid syntax, not actual values
}

int main()
{
    sum_doubles(2.91, 2.2);
    sum_doubles(2.91f, 2.2f);

    // error - concept is unsatisfied, requires doubles only
    /*sum_doubles(9, 2);*/

    multiply(2, 2.2);

    // char and string are not multipliable
    /*multiply('2', "world");*/

    return 0;
}