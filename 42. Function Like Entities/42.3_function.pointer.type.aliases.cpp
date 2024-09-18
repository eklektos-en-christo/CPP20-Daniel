//
// Created by Εκλεκτός εν Χριστώ on 7/13/24.
//

/*
 * to reduce the function pointer syntax, we can use type aliases for shorter names
 *
 * we can use type aliases to setup callbacks also
 */

#include <iostream>
#include "type_aliases/BoxContainer.h"

char encrypt(const char& c)
{
    return static_cast<char> (c + 10);
}

char decrypt(const char& c)
{
    return static_cast<char> (c - 10);
}

std::string& modify(std::string& input_string, char (*modifier)(const char&))
{
    for (std::size_t i{0}; i < input_string.size(); ++i)
        input_string[i] = modifier(input_string[i]);

    return input_string;
}

BoxContainer<std::string>& modify(BoxContainer<std::string>& sentence, char(*modifier)(const char&))
{
    for (std::size_t i{0}; i < sentence.size(); ++i)
    {
        for (std::size_t j{0}; j < sentence.get_item(i).size(); ++j)
            sentence.get_item(i)[j] = modifier(sentence.get_item(i)[j]);
    }
    return sentence;
}

// name is not needed inside (*) - name is on the left side now
// using a type alias to shorten the function pointer parameter
using str_comparator = bool(*)(const std::string& str1, const std::string& str2);

// old way of type aliasing
/*typedef bool(*str_comparator_old)(const std::string& str1, const std::string& str2);*/

// using the type alias in place of function pointer parameter
std::string get_best(const BoxContainer<std::string>& sentence, str_comparator comparator)
{
    std::string best{ sentence.get_item(0) };

    for (std::size_t i{0}; i < sentence.size(); ++i)
    {
        if (comparator(sentence.get_item(i), best))
            best = sentence.get_item(i);
    }
    return best;
}

bool larger_in_size(const std::string& str1, const std::string& str2)
{
    if (str1.size() > str2.size())
        return true;
    else
        return false;
}

bool lexographically_greater(const std::string& str1, const std::string& str2)
{
    return str1 > str2;
}

int main()
{
    BoxContainer<std::string> quote;

    quote.add("The");
    quote.add("Dog");
    quote.add("is");
    quote.add("an");
    quote.add("animal.");

    std::cout << modify(quote, encrypt) << '\n';
    std::cout << modify(quote, decrypt) << '\n';

    std::cout << get_best(quote, larger_in_size) << '\n';
    std::cout << get_best(quote, lexographically_greater) << '\n';

    return 0;
}