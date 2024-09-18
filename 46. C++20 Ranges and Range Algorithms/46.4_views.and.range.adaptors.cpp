//
// Created by Εκλεκτός εν Χριστώ on 8/16/24.
//

/*
 * view - is really a range, it doesn't own the data but grab it for viewing
 *
 * they are easy to copy and can be passed to functions
 *
 * we can filter the data using views, like viewing only odds from evens numbers
 *
 * range adaptors - transforms, filters, or otherwise manipulates a range, they produce views
 *
 * views - don't modify the data, live in ranges namespace
 * range adaptors - don't modify the data but create new views from data which are modified, live in views
 * namespace
 *
 * use range adaptors to get views
 */

#include <iostream>
#include <vector>
#include <ranges>                               // for views and range adaptors

void print_view(auto view)
{
    for (auto element : view)
        std::cout << element << ' ';
    std::cout << '\n';
}

int main()
{
    std::vector<int> vector{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // predicate, to be used by the view
    auto is_even{ [](int n){ return n % 2 == 0; } };

    // setting up a view, this filter the even numbers from vector
    // this is not a computation, it is just a setup of view which specifies the action to perform
    // this specification can be passed to functions for the actual computation
    std::ranges::filter_view v_evens{ std::ranges::filter_view(vector, is_even) };

    // computation happens in the print function
    print_view(v_evens);

    // passing a view on the fly
    print_view(std::ranges::filter_view(vector, [](int n){ return n % 2 != 0; }));

    print_view(vector);

    // creates a transformed view of vector, original data remains unchanged
    std::ranges::transform_view v_transformed{
            std::ranges::transform_view(vector, [](int n){return n * 10;}) };

    // computation happens here
    print_view(v_transformed);

    print_view(vector);

    // takes only 4 elements
    std::ranges::take_view view_taken{ std::ranges::take_view(vector, 4) };

    // computation happens here
    print_view(view_taken);

    // take a view of the vector while the number is odd, only 1 is odd in vector, at number 2
    // the predicate returns false and only 1 is added to the view
    std::ranges::take_while_view view_taken_while{ std::ranges::take_while_view(vector,
                                                                                [](int n){
        return (n % 2 != 0);
    }) };

    print_view(view_taken_while);

    // drops the 4 elements from the vector and then saves the rest in the view
    std::ranges::drop_view drop_elements{ std::ranges::drop_view(vector, 4) };

    print_view(drop_elements);

    // drop the first odd elements from the vector while predicate is true
    std::ranges::drop_while_view drop_elements_while{ std::ranges::drop_while_view
                                                              (vector, [](int n)
                                                              {
                                                                  return n % 2 != 0;
                                                              })};

    print_view(drop_elements_while);

    std::vector<std::pair<int, std::string>> pair_vector{ {1, "one"}, {2, "two"} };

    /*auto keys_view{ std::ranges::keys_view(pair_vector) };*/

    // range adaptor, lives in views namespace, through it, we can view either keys or values
    // only view values from the pair_vector
    auto keys_view{ std::views::values(pair_vector) };

    print_view(keys_view);

    auto is_odd{ [](int n){ return n % 2 != 0; } };

    // using a range adaptor to filter the odd elements from vector
    // namespace is ::views, not ::ranges
    auto odds_only{ std::views::filter(vector, is_odd) };

    print_view(odds_only);

    return 0;
}