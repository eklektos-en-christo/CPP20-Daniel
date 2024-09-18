//
// Created by Εκλεκτός εν Χριστώ on 6/27/24.
//

#ifndef PRACTICE_BOXCONTAINER_H
#define PRACTICE_BOXCONTAINER_H

#include <iostream>

template <class T, std::size_t max>
class BoxContainer
{
//    using value_type = int;
    static const std::size_t DEFAULT_CAPACITY{ 30 };
    static const std::size_t EXPAND_STEPS{ 5 };

public:
    BoxContainer(std::size_t capacity=DEFAULT_CAPACITY);
    BoxContainer(const BoxContainer<T, max>& src);
    ~BoxContainer();

    /*virtual void stream_insert(std::ostream& out) const override;*/

    std::size_t size() const { return m_size; }
    std::size_t capacity() const { return m_capacity; }

    void add(const T& item);
    bool remove_item(const T& item);
    std::size_t remove_all(const T& item);
    T get_item(std::size_t index) { return m_items[index]; }

    void operator+=(const BoxContainer<T, max>& src);
    void operator=(const BoxContainer<T, max>& src);

private:
    void expand(std::size_t new_capacity);

private:
    T* m_items{};
    std::size_t m_size{};
    std::size_t m_capacity{};
};

template <class T, std::size_t max>
BoxContainer<T, max>::BoxContainer(std::size_t capacity)
{
    m_items = new T[capacity];
    m_capacity = capacity;
    m_size = 0;
}

template <class T, std::size_t max>
BoxContainer<T, max>::BoxContainer(const BoxContainer<T, max>& src)
{
    m_items = new T[src.m_capacity];
    m_capacity = src.m_capacity;
    m_size = src.m_size;

    for (std::size_t i{}; i < src.m_size; ++i)
        m_items[i] = src.m_items[i];
}

template <class T, std::size_t max>
BoxContainer<T, max>::~BoxContainer()
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

template <class T, std::size_t max>
void BoxContainer<T, max>::expand(std::size_t new_capacity)
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

template <class T, std::size_t max>
void BoxContainer<T, max>::add(const T& item)
{
    if (m_size == m_capacity)
        expand(m_size + EXPAND_STEPS);

    m_items[m_size] = item;
    ++m_size;
}

template <class T, std::size_t max>
bool BoxContainer<T, max>::remove_item(const T& item)
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

template <class T, std::size_t max>
std::size_t BoxContainer<T, max>::remove_all(const T& item)
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

template <class T, std::size_t max>
void BoxContainer<T, max>::operator+=(const BoxContainer<T, max>& src)
{
    if ((m_size + src.m_size) > m_capacity)
        expand(m_size + src.m_size);

    for (std::size_t i{}; i < src.m_size; ++i)
        m_items[m_size + i] = src.m_items[i];

    m_size += src.m_size;
}

template <class T, std::size_t max>
void BoxContainer<T, max>::operator=(const BoxContainer<T, max>& src)
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

template <class T, std::size_t max>
BoxContainer<T, max> operator+(const BoxContainer<T, max>& left, const BoxContainer<T, max>& right)
{
    BoxContainer<T, max> new_box{ left.size() + right.size() };

    new_box += left;
    new_box += right;

    return new_box;
}

template <class T, std::size_t max>
std::ostream& operator<<(std::ostream& out, BoxContainer<T, max>& operand)
{
    for (std::size_t i{0}; i < operand.size(); ++i)
        out << operand.get_item(i) << ' ';

    out << "- max: " << max;

    return out;
}

#endif //PRACTICE_BOXCONTAINER_H
