//
// Created by Εκλεκτός εν Χριστώ on 6/25/24.
//

/*
 * if there is an unhandled exception, the function std::terminate will be called, which in
 * turn calls the std::abort to kill the program
 *
 * std::terminate - <exception>
 * std::abort - <cstdlib>
 *
 * we can set our own terminate function and do some stuff and then call the abort function
 * we can also use a lambda function to do the same
 *
 * program is still killed if we dont call abort()
 */

#include <iostream>
#include <thread>
#include <chrono>
#include <exception>        // for set_terminate


void our_terminate()
{
    std::cout << "Inside our_terminate()\n";
    std::cout << "Unhandled exception(s) found, terminating the program in 10s....\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(10000));
    std::abort();
}

int main()
{
    // setting our own terminate function to end the program according to this function
    /*std::set_terminate(&our_terminate);*/

    // using the lambda to do the same thing
    std::set_terminate
    ([]()
    {
        std::cout << "Inside lambda\n";
        std::cout << "Unhandled exception(s) found, terminating the program in 10s....\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(10000));
        std::abort();
    });

    // unhandled exception - calls terminate and abort
    throw 0;

    return 0;
}