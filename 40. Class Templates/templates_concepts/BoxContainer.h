//
// Created by Εκλεκτός εν Χριστώ on 6/27/24.
//

#ifndef PRACTICE_BOXCONTAINER_H
#define PRACTICE_BOXCONTAINER_H

#include <iostream>
#include <cstring>
#include <concepts>

template <class T>
// constraining our type using concept
// which says that type should have a default ctor
requires std::is_default_constructible_v<T>
class BoxContainer
{
    static const std::size_t DEFAULT_CAPACITY{ 30 };
    static const std::size_t EXPAND_STEPS{ 5 };

public:
    friend std::ostream& operator<<(std::ostream& out, BoxContainer<T>& operand)
    {
        for (std::size_t i{0}; i < operand.m_size; ++i)
            out << operand.m_items[i] << ' ';
        return out;
    }

    BoxContainer(std::size_t capacity=DEFAULT_CAPACITY);
    BoxContainer(const BoxContainer<T>& src);
    ~BoxContainer();

    std::size_t size() const { return m_size; }
    std::size_t capacity() const { return m_capacity; }

    void add(const T& item);
    bool remove_item(const T& item);
    std::size_t remove_all(const T& item);
    T get_item(std::size_t index) { return m_items[index]; }
    T get_max() const;

private:
    void expand(std::size_t new_capacity);

private:
    T* m_items{};
    std::size_t m_size{};
    std::size_t m_capacity{};
};

template <class T> requires std::is_default_constructible_v<T>
BoxContainer<T>::BoxContainer(std::size_t capacity)
{
    m_items = new T[capacity];
    m_capacity = capacity;
    m_size = 0;
}

template <class T> requires std::is_default_constructible_v<T>
BoxContainer<T>::BoxContainer(const BoxContainer<T>& src)
{
    m_items = new T[src.m_capacity];
    m_capacity = src.m_capacity;
    m_size = src.m_size;

    for (std::size_t i{}; i < src.m_size; ++i)
        m_items[i] = src.m_items[i];
}

template <class T> requires std::is_default_constructible_v<T>
BoxContainer<T>::~BoxContainer()
{
    delete[] m_items;
}

template <class T> requires std::is_default_constructible_v<T>
void BoxContainer<T>::expand(std::size_t new_capacity)
{
    T* new_items{};

    if (new_capacity == m_capacity)
        return;

    new_items = new T[new_capacity];

    for (std::size_t i{}; i < m_size; ++i)
        new_items[i] = m_items[i];

    delete[] m_items;

    m_items = new_items;
    m_capacity = new_capacity;
}

template <class T> requires std::is_default_constructible_v<T>
void BoxContainer<T>::add(const T& item)
{
    if (m_size == m_capacity)
        expand(m_size + EXPAND_STEPS);

    m_items[m_size] = item;
    ++m_size;
}

template <class T> requires std::is_default_constructible_v<T>
bool BoxContainer<T>::remove_item(const T& item)
{
    std::size_t index{ m_capacity + 999 };

    // find the target item
    for (std::size_t i{}; i < m_size; ++i)
    {
        if (m_items[i] == item)
        {
            index = i;
            break;
        }
    }

    // target not found
    if (index > m_size)
        return false;

    // target found
    m_items[index] = m_items[m_size - 1];
    --m_size;
    return true;
}

template <class T> requires std::is_default_constructible_v<T>
std::size_t BoxContainer<T>::remove_all(const T& item)
{
    std::size_t remove_count{};

    bool removed{ remove_item(item) };

    if (removed)
        ++remove_count;

    while (removed)
    {
        removed = remove_item(item);

        if (removed)
            ++remove_count;
    }

    return remove_count;
}

template <class T> requires std::is_default_constructible_v<T>
T BoxContainer<T>::get_max() const
{

    std::cout << "non specialized get_max() called\n";

    std::size_t max_index{};

    for (std::size_t i{0}; i < m_size; ++i)
    {
        if (m_items[i] > m_items[max_index])
            max_index = i;
    }

    return m_items[max_index];
}

// specialized max function for char* type
// inline - to constrain the definition to this TU only
// or we can move the definition in the source file of this TU
template <> inline
char* BoxContainer<char*>::get_max() const
{

    std::cout << "get_max() specialized for char* called\n";

    std::size_t max_index{};

    for (std::size_t i{0}; i < m_size; ++i)
    {
        if (strcmp(m_items[i], m_items[max_index]) > 0)
            max_index = i;
    }

    return m_items[max_index];
}

#endif //PRACTICE_BOXCONTAINER_H
