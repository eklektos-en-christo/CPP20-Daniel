//
// Created by Εκλεκτός εν Χριστώ on 7/13/24.
//

/*
 * function ptrs : using ptrs to store address of the functions and then use the address to call them
 *
 * syntax:
 *
 *      return (*fptr_name) (params...) { &function_that_needs_to_be_stored_in_fptr };
 *                                      // & is optional
 *
 *      we can use auto type deduction
 *
 *                      auto fptr{ &function };
 *                      auto* fptr{ function }
 *
 * usage:           fptr(args);         // like a normal function call
 *
 * we can initialize function ptrs to nullptr also, auto can't be used with fptr initializatio to null
 * don't call fptrs with nullptr
 */

#include <iostream>

// a normal function
double function(double a, double b)
{
    return a + b;
}

int main()
{
    // setting a function pointer to function()
    // auto or return type can be used
    // param names are optional
    // & is optional
    auto (*f_ptr) (double, double){ &function };

    // calling like a normal function using the ptr
    std::cout << f_ptr(2.8, 6.2) << '\n';

    // possible, but auto can't be used here
    int (*f_ptr2) () = nullptr;

    // accessing fptr with nullptr will cause segmentation fault
    /*std::cout << f_ptr2() << '\n';*/

    // another syntax - auto function pointer deduction
    auto f_ptr3{ function };

    // another syntax
    auto* f_ptr4{ function };

    // return type should be same as of the function
    /*int (*f_ptr_int) (double, double) = function;*/

    // full prototype is required
    /*double (*f_ptr_double) = &function;*/

    return 0;
}