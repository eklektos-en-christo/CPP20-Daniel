//
// Created by Εκλεκτός εν Χριστώ on 7/15/24.
//

/*
 * a functor is an object, so it can store the state also, regular function pointers can't store the state
 * because they are not objects
 */

#include "functor_parameters/BoxContainer.h"
#include <concepts>

template <typename T>
requires std::is_arithmetic_v<T>        // only arithmetic types can be used
class IsInRange
{
public:
    IsInRange(T min, T max) : min_inclusive{min}, max_inclusinve{max}{}

    bool operator()(T value) const
    {
        return (value >= min_inclusive) && (value <= max_inclusinve);
    }

private:
    T min_inclusive{};
    T max_inclusinve{};
};

template <typename T, typename Rangepicker>
requires std::is_arithmetic_v<T>
T range_sum(const BoxContainer<T>& collection, Rangepicker is_in_range)
{
    T sum{};

    for (std::size_t i{}; i < collection.size(); ++i)
    {
        if (is_in_range(collection.get_item(i)))
            sum += collection.get_item(i);
    }
    return sum;
}

int main()
{
    BoxContainer<double> doubles_box;
    doubles_box.add(22.1);
    doubles_box.add(11.2);
    doubles_box.add(19.6);
    doubles_box.add(9.8);

    // we can pass a functor/function pointer/standard functor/normal function as a callback
    std::cout << range_sum(doubles_box, IsInRange<double>{ 5.5, 15.0 })
              << '\n';

    std::cout << range_sum(doubles_box, IsInRange<double> { 0.0, 30.0 })
              << '\n';

    // concept failure - only numbers can be supplied
    /*std::cout << range_sum(doubles_box, IsInRange<std::string> { "0.0", "30.0" })
              << '\n';*/

    return 0;
}