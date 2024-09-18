//
// Created by Εκλεκτός εν Χριστώ on 8/13/24.
//

/*
 * std::find - finds the element and returns an iterator to that value
 */

#include <iostream>
#include <algorithm>

int main()
{
    int collection[] {10, 5, 2};

    int element_to_find{ 2 };

    auto result = std::find(std::begin(collection), std::end(collection),
                             element_to_find);

    // find returns an iterator to the found element, if not found then it returns the end iterator
    // checking if the return iterator is pointing to the end
    if (result != std::end(collection))
        std::cout << "Element found: " << *result << '\n';
    else
        std::cout << "Element not found\n";

    auto predicate{ [](int n) {
        if (n % 2 != 0)
            return true;
        return false;
    } };

    auto result_pred{ std::find_if(std::begin(collection),
                                   std::end(collection), predicate) };

    if (result_pred != std::end(collection))
        std::cout << "At least one element is odd in collection: " << *result_pred << '\n';
    else
        std::cout << "No odd element is in collection\n";

    return 0;
}