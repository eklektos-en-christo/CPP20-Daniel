//
// Created by Εκλεκτός εν Χριστώ on 7/6/24.
//

/*
 * similar to the default parameters in functions, we can specify the default value for template
 * parameters, when not specified, they are automatically picked up by the compiler to generate
 * template of the default specified type
 *
 * order of the default parameters matter, always put type paramters first and non type parameters
 * second
 *
 * default values are specified only once, above the class declaration in the template declaration
 *
 * -----------------------------------------------------------------------------------------
 * explicit template instantiation: we can explicitly instantiate the template with specific
 * type without creating an object, this also works with the standalone template functions
 *
 * template class classname<template args>;
 * template func_proto<template args>(func_params);
 *
 * these line will be replaced by an instance of the template with same arguments, this will
 * also generate the member functions which are not being used in the code(main())
 */

#include "default_values/BoxContainer.h"

int main()
{
    // default value are passed: <int, 20>
    BoxContainer box1;
    std::cout << box1 << '\n';

    // overridden the int with double and 20 is used as default value for non type parameter
    BoxContainer<double> box2;
    std::cout << box2 << '\n';

    return 0;
}