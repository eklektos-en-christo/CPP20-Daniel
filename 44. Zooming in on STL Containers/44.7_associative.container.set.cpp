//
// Created by Εκλεκτός εν Χριστώ on 8/6/24.
//

/*
 * set : automatically orders the data in memory, the elements stored inside must be comparable or
 * should provide operator<, duplicates are not allowed and are ignored if provided, lives in <set>
 *
 * custom functors and callbacks can also be used for ordering the elements of a set
 */

#include <iostream>
#include <set>
#include <string_view>
#include <functional>

class Book
{
    friend std::ostream& operator<< (std::ostream& out, const Book& book)
    {
        out << "[" << book.m_year << ", " << book.m_title << ']';
        return out;
    }

public:
    Book(int year, std::string_view title)
        : m_year{ year }, m_title{ title }
    {
    }

    // operator< for std::set to compare and order the elements
    bool operator<(const Book& right) const
    {
        return this->m_year < right.m_year;
    }

private:
    int m_year{};
    std::string m_title{};
};

template <typename T>
void print_collection(const T& collection)
{
    auto it{ collection.begin() };

    while (it != collection.end())
    {
        std::cout << *it << ' ';
        ++it;
    }
    std::cout << '\n';
}

// comparator function - can be used with std::set for ordering the elements
class IntComparator
{
public:
    bool operator()(int left, int right) const
    {
        return left < right;
    }
};

// function pointer comparator - can be used as a callback to std::set template args
bool compare_ints(int left, int right)
{
    return left < right;
}

int main()
{
    // 1 is a duplicate and is ignored
    std::set<int> set1{ 2, 99, 7, 1, 0, -6, 4, 1 };

    // elements are in order automatically
    print_collection(set1);

    std::set<Book> book_set{ {2011, "CPP Mastery"}, {2001, "C Prog"} };

    // books are ordered on the basis of operator<, defined in Books type
    print_collection(book_set);

    auto it_reverse{ set1.rbegin() };

    while (it_reverse != set1.rend())
    {
        std::cout << *it_reverse << ' ';
        ++it_reverse;
    }
    std::cout << '\n';

    std::cout << set1.size() << '\n';
    std::cout << set1.max_size() << '\n';
    std::cout << set1.empty() << '\n';

    auto insertion_success{ set1.insert(5) };
    print_collection(set1);

    // insert() returns a std::pair, first data member is an iterator to the inserted element
    // second data member is the boolean ouptut of the insertion operation - true/false
    if (insertion_success.second)
        std::cout << "Insertion successful: " << *insertion_success.first << '\n';
    else
        std::cout << "Insertion unsuccessful\n";

    auto emplace_success{ set1.emplace(18) };

    if (emplace_success.second)
        std::cout << "Emplace successful: " << *emplace_success.first << '\n';
    else
        std::cout << "Emplace unsuccessful\n";

    print_collection(set1);

    // by default the set uses std::less functor for ordering the data
    // setting the custom functor for ordering of elements
    /*std::set<int, std::greater<int>> greater_order{ 1, 2, 3, 4, 5 };*/

    // custom functor
    /*std::set<int, IntComparator> greater_order{ 1, 4, 2, 3, 5 };*/

    // function pointer callback as a comprarator, initialization is not possible
    // syntax is different
    /*std::set<int, bool(*)(int,int)> greater_order(compare_ints);
    greater_order.insert({ 1, 4, 2, 3, 5 });*/

    // a lambda function callback as a comparator
    std::set<int, std::function<bool(int,int)>> greater_order([](int left, int right){
        return left < right;
    });
    greater_order.insert({ 1, 4, 2, 3, 5 });

    print_collection(greater_order);

    return 0;
}