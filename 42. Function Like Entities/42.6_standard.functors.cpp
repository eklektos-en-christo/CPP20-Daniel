//
// Created by Εκλεκτός εν Χριστώ on 7/14/24.
//

/*
 * standard functors live in <functional>
 * we can pass standard functors, custom functors or function pointers as callbacks to functions
 */

#include <functional>
#include "standard_functors/BoxContainer.h"

template <typename T, typename Comparator>
T get_best(const BoxContainer<T>& sentence, Comparator comparator)
{
    T best{ sentence.get_item(0) };

    for (std::size_t i{0}; i < sentence.size(); ++i)
    {
        if (comparator(sentence.get_item(i), best))
            best = sentence.get_item(i);
    }
    return best;
}

/**********************************************************************************************/
// normal comparator function
template <typename T>
bool custom_greater(const T& param1, const T& param2)
{
    return param1 > param2;
}

/**********************************************************************************************/
// custom functor - overloads the ()
template <typename T>
class Greater
{
public:
    bool operator()(const T& param1, const T& param2)
    {
        return param1 > param2;
    }
};

/**********************************************************************************************/
// inbuilt standard templated functors
// they internally overload the () operator
std::plus<int> adder;
std::greater<int> compare_greater;
std::minus<int> subtractor;
std::greater<std::string> string_greater;

/**********************************************************************************************/

int main()
{
    // using std functors as callable objects with parameters
    std::cout << adder(2, 3) << '\n';
    std::cout << compare_greater(6, 3) << '\n';
    std::cout << subtractor(10, 6) << '\n';

    BoxContainer<std::string> quote;

    quote.add("The");
    quote.add("Dog");
    quote.add("is");
    quote.add("an");
    quote.add("animal.");

    // using normal function as callback
    std::cout << get_best(quote, custom_greater<std::string>) << '\n';

    // using standard functor as callback
    std::cout << get_best(quote, string_greater) << '\n';
    // standard functors can directly be passed as a callback
    std::cout << get_best(quote, std::greater<std::string>{}) << '\n';

    // using custom functor as callback
    Greater<std::string> custom_functor_greater;
    std::cout << get_best(quote, custom_functor_greater) << '\n';

    return 0;
}