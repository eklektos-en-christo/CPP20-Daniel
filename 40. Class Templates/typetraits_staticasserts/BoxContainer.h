//
// Created by Εκλεκτός εν Χριστώ on 6/27/24.
//

#ifndef PRACTICE_BOXCONTAINER_H
#define PRACTICE_BOXCONTAINER_H

#include <iostream>
#include <cstring>

template <class T>
class BoxContainer
{
    static_assert(std::is_default_constructible_v<T>, "Type in the BoxContainer should have a default ctor.");

    static const std::size_t DEFAULT_CAPACITY{ 30 };
    static const std::size_t EXPAND_STEPS{ 5 };

public:

    // non member operator as a friend of the class template, <> is necesary for it work
    // private stuff of the class is accessible to the operator<<
    friend std::ostream& operator<< <T>(std::ostream& out, BoxContainer<T>& operand);

    BoxContainer(std::size_t capacity=DEFAULT_CAPACITY);
    BoxContainer(const BoxContainer<T>& src);
    ~BoxContainer();

    /*virtual void stream_insert(std::ostream& out) const override;*/

    std::size_t size() const { return m_size; }
    std::size_t capacity() const { return m_capacity; }

    void add(const T& item);
    bool remove_item(const T& item);
    std::size_t remove_all(const T& item);
    T get_item(std::size_t index) { return m_items[index]; }
    T get_max() const;

    void operator+=(const BoxContainer<T>& src);
    void operator=(const BoxContainer<T>& src);

private:
    void expand(std::size_t new_capacity);

private:
    T* m_items{};
    std::size_t m_size{};
    std::size_t m_capacity{};
};

template <class T>
BoxContainer<T>::BoxContainer(std::size_t capacity)
{
    m_items = new T[capacity];
    m_capacity = capacity;
    m_size = 0;
}

template <class T>
BoxContainer<T>::BoxContainer(const BoxContainer<T>& src)
{
    m_items = new T[src.m_capacity];
    m_capacity = src.m_capacity;
    m_size = src.m_size;

    for (std::size_t i{}; i < src.m_size; ++i)
        m_items[i] = src.m_items[i];
}

template <class T>
BoxContainer<T>::~BoxContainer()
{
    delete[] m_items;
}

//void BoxContainer::stream_insert(std::ostream &out) const
//{
//    out << "Size: " << m_size << ", ";
//    out << "Capacity: " << m_capacity << ", ";
//    out << "Items: ";
//
//    for (std::size_t i{}; i < m_size; ++i)
//    {
//        out << m_items[i] << ' ';
//    }
//}

template <class T>
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

template <class T>
void BoxContainer<T>::add(const T& item)
{
    if (m_size == m_capacity)
        expand(m_size + EXPAND_STEPS);

    m_items[m_size] = item;
    ++m_size;
}

template <class T>
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

template <class T>
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

template <class T>
void BoxContainer<T>::operator+=(const BoxContainer<T>& src)
{
    if ((m_size + src.m_size) > m_capacity)
        expand(m_size + src.m_size);

    for (std::size_t i{}; i < src.m_size; ++i)
        m_items[m_size + i] = src.m_items[i];

    m_size += src.m_size;
}

template <class T>
void BoxContainer<T>::operator=(const BoxContainer<T>& src)
{
    T* new_items{};

    if (this == &src)
        return;

    if (m_capacity != src.m_capacity)
    {
        new_items = new T[src.m_capacity];
        delete[] m_items;
        m_items = new_items;
        m_capacity = src.m_capacity;
    }

    for (std::size_t i{}; i < src.m_size; ++i)
        m_items[i] = src.m_items[i];

    m_size = src.m_size;
}

template <class T>
BoxContainer<T> operator+(const BoxContainer<T>& left, const BoxContainer<T>& right)
{
    BoxContainer<T> new_box{ left.size() + right.size() };

    new_box += left;
    new_box += right;

    return new_box;
}

// << can access private stuff of the class - friend of the class
template <class T>
std::ostream& operator<<(std::ostream& out, BoxContainer<T>& operand)
{
    for (std::size_t i{0}; i < operand.m_size; ++i)
        out << operand.m_items[i] << ' ';
    return out;
}


template <class T>
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
