//
// Created by Εκλεκτός εν Χριστώ on 8/7/24.
//

/*
 * std::map - stores data as key value pairs, like a std::pair, duplicates keys are not allowed but
 * duplicate values are allowed
 *
 * searching is fast because of the ordering of the elements
 *
 * lives in <map>
 */

#include <iostream>
#include <map>
#include <string>
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

template <typename T, typename K>
void print_map(const std::map<T, K>& map)
{
    auto it{ map.begin() };

    while (it != map.end())
    {
        std::cout << it->first << ", " << it->second << '\n';
        ++it;
    }
    std::cout << '\n';
}

int main()
{
    // ordering is based on the key information
    std::map<int, int> map1{ {11,101}, {2,202}, {3,303}, {4,404} };

    std::map<int, Book> book_map1{ {1, {2021,"book1"}},
                                   {0, {1992,"book2"}},
                                   {8, {2002,"book3"}}};

    print_map(map1);
    print_map(book_map1);

    for (const auto&[key, value] : book_map1)
        std::cout << key << ' ' << value << '\n';
    std::cout << '\n';

    for (const auto& book : book_map1)
        std::cout << book.first << ' ' << book.second << '\n';
    std::cout << '\n';

    // ordering is based on the key info. - lexicographically
    std::map<std::string, std::string> string_map{ {"Dan", "NY"},
                                                   {"Jude", "LA"},
                                                   {"Caleb", "TX"}};

    print_map(string_map);

    auto it{ string_map.begin() };

    while (it != string_map.end())
    {
        std::cout << (*it).first << ' ' << (*it).second << '\n';
        ++it;
    }
    std::cout << '\n';

    auto it_reverse{ string_map.rbegin() };

    // reverse iterator
    while (it_reverse != string_map.rend())
    {
        std::cout << (*it_reverse).first << ' ' << (*it_reverse).second << '\n';
        ++it_reverse;
    }
    std::cout << '\n';

    it = string_map.begin();

    // editing map values
    while (it != string_map.end())
    {
        string_map[it->first] = "something";
        ++it;
    }

    print_map(string_map);

    std::cout << string_map.size() << '\n';
    std::cout << string_map.max_size() << '\n';
    std::cout << string_map.empty() << '\n';

    auto result{ string_map.insert({"new", "data"}) };

    if (result.second)
        std::cout << result.first->second << '\n';

    auto emplace_result{ string_map.emplace("new data", "again") };

    if (emplace_result.second)
        std::cout << emplace_result.first->second << '\n';

    // custom comparator for ordering
    /*std::map<int, int, IntComparator> int_map{ {11,2}, {3,4} };*/

    // function pointer as a comparator for ordering
    /*std::map<int, int, bool(*)(int,int)> int_map{compare_ints };
    int_map.insert({{11,2}, {3,4}});*/

    // a lambda as a comparator for ordering
    std::map<int, int, std::function<bool(int,int)>> lambda_map([](int left, int right){
        return left > right;
    });
    lambda_map.insert({{11,2}, {3,4}});


    auto int_it{ lambda_map.begin() };

    while (int_it != lambda_map.end())
    {
        std::cout << int_it->first << '\n';
        ++int_it;
    }
    std::cout << '\n';

    return 0;
}