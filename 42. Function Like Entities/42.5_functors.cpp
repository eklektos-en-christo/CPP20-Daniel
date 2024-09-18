//
// Created by Εκλεκτός εν Χριστώ on 7/14/24.
//

/*
 * functors : function objects, objects that can be called like a function, it is done by overloading the
 * operator() for our type
 *
 * we can use functors as parameters/arguments in place of function pointer parameters
 * we can also return functors from functions, they are objects but act like functions
 */

#include "functors/Encrypt.h"
#include "functors/Decrypt.h"
#include <iostream>

char encrypt(const char& param)
{
    return static_cast<char> (param + 8);
}

char decrypt(const char& param)
{
    return static_cast<char> (param - 8);
}

template <typename Modifier>    // this allows us to pass functors or function pointers as callbacks
std::string& modify(std::string& str_param, Modifier modifier)
{
    for (std::size_t i{}; i < str_param.size(); ++i)
        str_param[i] = modifier(str_param[i]);
    return str_param;
}

int main()
{
    std::string string{ "functors" };

    // passing function pointers as callback functions
    std::cout << modify(string, encrypt) << '\n';
    std::cout << modify(string, decrypt) << '\n';

    Encrypt encrypt_functor;
    std::cout << encrypt_functor('A') << '\n';
    Decrypt decrypt_functor;
    std::cout << decrypt_functor('Z') << '\n';

    // passing functors as callback functions
    std::cout << modify(string, encrypt_functor) << '\n';
    std::cout << modify(string, decrypt_functor) << '\n';

    return 0;
}