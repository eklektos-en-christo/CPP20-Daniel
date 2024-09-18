//
// Created by Εκλεκτός εν Χριστώ on 7/26/24.
//

/* DOUBLE ENDED QUEUE - manipulations from both ends
 *
 * deque : fast insertions/removals from both ends of the container, bound checking is not available,
 * bound checking is available with at() method
 */

#include <iostream>
#include <deque>

class Item
{
public:
    Item() : m_var{0}{}
    explicit Item(int var) : m_var{var}{}
    Item(const Item& src) = default;
    int get() const { return m_var; }

private:
    int m_var;
};

std::ostream& operator<<(std::ostream& out, const Item& item)
{
    out << "Item: " << item.get();
    return out;
}

template <typename T>
void print_collection(const T& collection)
{
    auto it{ collection.begin() };

    while(it != collection.end())
    {
        std::cout << *it << ' ';
        ++it;
    }
    std::cout << '\n';
}

int main()
{
    std::deque<int> my_deque{ 1, 2, 3, 4, 5 };
    std::deque<Item> items_deque{ Item{2}, Item{3}, Item{9} };

    print_collection(my_deque);
    print_collection(items_deque);

    std::cout << my_deque[101] << '\n';         // no bound checks
    /*std::cout << my_deque.at(101) << '\n';*/   // bound checking

    std::cout << my_deque.front() << '\n';
    std::cout << my_deque.back() << '\n';

    auto rev_it{ my_deque.rbegin() };

    while (rev_it != my_deque.rend())
    {
        std::cout << *rev_it << ' ';
        ++rev_it;
    }
    std::cout << '\n';

    std::cout << my_deque.max_size() << '\n';
    std::cout << my_deque.size() << '\n';
    my_deque.push_back(22);
    std::cout << my_deque.size() << '\n';

    auto it_begin{ my_deque.begin() + 2 };

    // inserts the data in from of the interator specified
    my_deque.insert(it_begin, 100);

    print_collection(my_deque);

    std::cout << *it_begin << '\n';

    return 0;
}