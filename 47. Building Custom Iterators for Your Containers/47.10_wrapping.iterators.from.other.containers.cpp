//
// Created by Εκλεκτός εν Χριστώ on 9/2/24.
//

/*
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>

template <class T>
class VectorWrapper
{
public:
    // std::vector has iterators, we return those iterators from our own class
    // this allows us to use our class with std library, views, algos, ranges etc.
    std::vector<T>::iterator begin() { return m_items.begin(); }
    std::vector<T>::iterator end() { return m_items.end(); }

    std::vector<T>::const_iterator begin() const { return m_items.cbegin(); }
    std::vector<T>::const_iterator end() const { return m_items.cend(); }

    std::vector<T>::const_iterator cbegin() { return m_items.cbegin(); }
    std::vector<T>::const_iterator cend() { return m_items.cbegin(); }

    void add(T item) { m_items.push_back(item); }

    friend std::ostream& operator<<(std::ostream& out, const VectorWrapper<T>& vector)
    {
        for (auto i : vector)
            out << i << ' ';
        return out;
    }

private:
    std::vector<T> m_items;
};

int main()
{
    VectorWrapper<int> vector;
    vector.add(2);
    vector.add(1);
    vector.add(9);
    vector.add(8);

    std::cout << vector << '\n';



    return 0;
}