//
// Created by Εκλεκτός εν Χριστώ on 7/26/24.
//

/*
 * forward list : very fast insertions and removals from anywhere in the container
 *
 * it saves the data non contiguously at random addresses, element access is only in forward direction
 * it doesn't have [] operator, traversing is hard due to poor memory locality
 *
 * lives in <forward_list>
 */

#include <iostream>
#include <forward_list>

template <typename T>
void print_collection(const T& collection)
{
    auto begin_it{ collection.begin() };

    while (begin_it != collection.end())
    {
        std::cout << *begin_it << ' ';
        ++begin_it;
    }
    std::cout << '\n';
}

int main()
{
    std::forward_list<int> f_list{ 2, 4, 8, 10, 12 };

    print_collection(f_list);

    std::cout << f_list.front() << '\n';

    // this returns an iterator before the first element in collection
    auto before_it{ f_list.before_begin() };

    // adding element before the beginning of the list
    f_list.insert_after(before_it, 0);

    print_collection(f_list);

    // places the element after the iterator
    f_list.emplace_after(before_it, 1);

    print_collection(f_list);

    // problem code
    /*auto erase_it{ std::find(f_list.begin(), f_list.end(), 1) };*/

    f_list.pop_front();
    f_list.pop_front();

    print_collection(f_list);

    f_list.resize(3);

    print_collection(f_list);

    // resizing deletes the elements
    f_list.resize(5);

    print_collection(f_list);

    std::forward_list<int> f_list2{ 10, 20 };

    f_list.merge(f_list2);

    std::cout << "f_list1: ";
    print_collection(f_list);

    std::cout << "f_list2: ";
    print_collection(f_list2);

    f_list.clear();
    f_list2.clear();

    f_list = { 1, 2, 3, 4, 5 };
    f_list2 = { 3, 6, 10, 8, 13, 20, 9, 4 };

    // moving a range of data from one flist to another flist
    f_list.splice_after(f_list.before_begin(), f_list2, f_list2.before_begin(), f_list2.end());

    print_collection(f_list);
    print_collection(f_list2);

    // removes the element specified, duplicates also
    f_list.remove(3);

    print_collection(f_list);

    // predicate - callback, remove element if it is greater than 5
    f_list.remove_if([](int n){ return n > 5; });

    print_collection(f_list);
    
    f_list.reverse();

    print_collection(f_list);

    f_list = { 2, 2, 1, 2, 3 };
    print_collection(f_list);
    // removes the contiguous duplicates
    f_list.unique();
    print_collection(f_list);

    f_list.sort();
    print_collection(f_list);
    f_list.unique();
    print_collection(f_list);

    return 0;
}