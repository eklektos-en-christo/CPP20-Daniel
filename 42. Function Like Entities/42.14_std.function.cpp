//
// Created by Εκλεκτός εν Χριστώ on 7/16/24.
//

/*
 * std::function - facility in cpp to make it easy to use functors, normal funcitons, lambdas, function
 * pointers etc., live in <functional>
 *
 * it can store any kind of function entity
 *
 * it takes the signature of the function like entities
 *
 * syntax:      std::function<returntype(params)> var_name;
 *
 * this also solves the problem when we have to store callbacks in a container, the template argument
 * for the type we want to store in container can be specified in std::function, because std::function
 * can take function entities but container can only take the type which is to be stored inside of the
 * container
 *
 * we can use std::function as callback parameter in functions, this will allow to pass any function
 * like entities to the function
 */

#include "std_function/BoxContainer.h"
#include <functional>

char encrypt(const char& param)
{
    return static_cast<char> (param + 8);
}

char decrypt(const char& param)
{
    return static_cast<char> (param - 8);
}

class Decrypt
{
public:
    char operator()(const char& c) { return static_cast<char> (c - 8); }
};

// using the std::function to pass funtion like entities to this function as callbacks
std::string& modify(std::string& str_param, const std::function<char(const char&)>& modifier)
{
    for (std::size_t i{}; i < str_param.size(); ++i)
        str_param[i] = modifier(str_param[i]);
    return str_param;
}

int main()
{
    // storing a function like entitiy into std::function
    std::function<char(const char&)> modifier;

    // storing a function pointer
    modifier = encrypt;
    std::cout << modifier('t') << '\n';

    // storing a function pointer
    modifier = decrypt;
    std::cout << modifier('|') << '\n';

    // storing a functor - the return type and params of entity should match the std::function
    Decrypt decrypt_functor;
    modifier = decrypt_functor;
    std::cout << modifier('X') << '\n';

    // storing a lambda
    modifier = [](const char& c){ return c + 8; };
    std::cout << modifier('A') << '\n';

    // we can store function like entities in a container also using std::function
    BoxContainer<std::function<char(const char&)>> entities_box;
    entities_box.add(encrypt);
    entities_box.add(decrypt);
    entities_box.add(modifier);
    entities_box.add(decrypt_functor);

    for (std::size_t i{0}; i < entities_box.size(); ++i)
        std::cout << "Container: " << entities_box.get_item(i)('A') << '\n';

    std::string str{ "Hello" };

    // std::function parameter can take all kind of function entities as callbacks
    std::cout << modify(str, encrypt) << '\n';
    std::cout << modify(str, decrypt_functor) << '\n';
    std::cout << modify(str, modifier) << '\n';

    return 0;
}