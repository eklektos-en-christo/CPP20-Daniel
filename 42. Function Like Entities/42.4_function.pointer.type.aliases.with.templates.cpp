//
// Created by Εκλεκτός εν Χριστώ on 7/14/24.
//

/*
 * templates type aliases for function  pointers don't work with typedefs, don't use them
 *
 * we can template a type alias for function pointer to let our callback functions work with different
 * types
 */

#include "type_aliases_templates/BoxContainer.h"

// a templated type alias for function pointer
template <typename T>
using compare_T = bool(*)(const T&, const T&);

template <typename T>
T get_best(const BoxContainer<T>& sentence, compare_T<T> comparator)
{
    T best{ sentence.get_item(0) };

    for (std::size_t i{0}; i < sentence.size(); ++i)
    {
        if (comparator(sentence.get_item(i), best))
            best = sentence.get_item(i);
    }
    return best;
}

// callback functions for different type comparisons
/**********************************************************************/
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

bool larger_int(const int& param1, const int& param2)
{
    return param1 > param2;
}

// a templated callback function, can work with different types
template <typename T>
bool smaller(const T& param1, const T& param2)
{
    if (param1 < param2)
        return true;
    return false;
}
/**********************************************************************/

int main()
{
    BoxContainer<std::string> quote;

    quote.add("The");
    quote.add("Dog");
    quote.add("is");
    quote.add("an");
    quote.add("animal.");

    std::cout << get_best(quote, larger_in_size) << '\n';
    std::cout << get_best(quote, lexographically_greater) << '\n';

    BoxContainer<int> int_boxes;

    int_boxes.add(2);
    int_boxes.add(89);
    int_boxes.add(12);
    int_boxes.add(72);

    std::cout << get_best(int_boxes, larger_int) << '\n';
    std::cout << get_best(int_boxes, smaller) << '\n';

    return 0;
}