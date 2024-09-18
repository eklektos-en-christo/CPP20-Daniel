//
// Created by Εκλεκτός εν Χριστώ on 7/18/24.
//

/*
 * constant iterators : by default, iterators can modify the data they point to, but const iterators
 * can't do
 *
 * cbegin() returns a const iterator, there are also the const reverse iterators crbegin crend
 *
 * if the container is a const, then iterators will be const
 */

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> int_vector{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // cbegin return a const iterator
    auto const_iter{ int_vector.cbegin() };

    // another syntax, without auto type deduction
    /*std::vector<int>::const_iterator const_iter{ int_vector.cbegin() };*/

    while (const_iter != int_vector.cend())
    {
        /**const_iter = 0;*/                    // const iterator can't write data
        std::cout << *const_iter << ' ';        // const iterator can read
        ++const_iter;
    }
    std::cout << '\n';

    const std::vector<int> const_vector{ 1, 2, 3 };

    while (const_vector.begin() != const_vector.end())
    {
        // a const type return a const iterator by default
        // begin() returns a const iterator
        /**const_vector.begin() = 0;*/
        ++const_vector.begin();
    }

    return 0;
}