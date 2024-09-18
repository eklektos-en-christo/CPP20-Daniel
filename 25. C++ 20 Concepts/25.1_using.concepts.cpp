//
// Created by Εκλεκτός εν Χριστώ on 29/02/2024.
//

/*
 * concepts - mechanism to place constraints on template type parameters, we can use
 * concepts to specify that we want our function template to only be called with
 * integral type or another type etc. and if requirements are not met then compiler error
 *
 * two sides of concepts:
 * - built in concepts in std library
 * - custom concepts
 *
 * syntax 1:
 *
 *              template <params>
 *              requires std::concept_name<template_parameter>
 *              T func_name(T, T)
 *              {
 *                  // body logic
 *              }
 *
 * the function will work only if the concept is satisfied
 *
 * syntax 2:    we can also use type traits with concepts, the expression after requires clause
 * should evaluate to true(boolean value) at compile time
 *
 *
 *              template <params>
 *              requires std::type_trait<T>
 *              T func_name(T)
 *              {
 *                  body
 *              }
 *
 * syntax 3: we can also use the concepts in template declaration, once specified, the concept
 * is going to be forced on the function template
 *
 *              template <concept_name T>
 *              T func_name(T)
 *              {
 *                  body
 *              }
 *
 * syntax 4: we can use concepts with auto function templates, just add the concept in front of
 * auto keyword in function parameters
 *
 *              auto func_name(concept auto a, concept auto b)
 *              {
 *                  body
 *              }
 *
 * syntax 5: after the parameter list, we can put the requires clause
 *
 *              typename <params>
 *              T func_name(T,T) requires concept_name<T>
 *              {
 *                  body
 *              }
 */

#include <iostream>
#include <concepts>         // necessary for using concepts

/*template <typename T>
requires std::integral<T>   // putting an integral constrain on the template function
T sum(T a, T b)
{
    return a + b;
}*/

// syntax 2
/*template <std::integral T>
T sum(T a, T b)
{
    return a + b;
}*/

// syntax 3
/*auto sum(std::integral auto a, std::integral auto b)
{
    return a + b;
}*/

// syntax 4
template <typename T>
T sum(T a, T b) requires std::integral<T>
{
    return a + b;
}

int main()
{
    sum(2, 2);
    /*sum(3, 9.8);*/        // only integral types can be used to call sum()

    return 0;
}