//
// Created by Εκλεκτός εν Χριστώ on 6/27/24.
//

#include "BoxContainer.h"

BoxContainer::BoxContainer(std::size_t capacity)
    : m_items{ new value_type[capacity] }, m_capacity{ capacity }, m_size{ 0 }
{

}

// copy ctor
BoxContainer::BoxContainer(const BoxContainer &src)
{
    m_items = new value_type[src.m_capacity];
    m_capacity = src.m_capacity;
    m_size = src.m_size;

    for (std::size_t i{}; i < src.m_size; ++i)
        m_items[i] = src.m_items[i];
}

BoxContainer::~BoxContainer()
{
    delete[] m_items;
}

void BoxContainer::stream_insert(std::ostream &out) const
{
    out << "Size: " << m_size << ", ";
    out << "Capacity: " << m_capacity << ", ";
    out << "Items: ";

    for (std::size_t i{}; i < m_size; ++i)
    {
        out << m_items[i] << ' ';
    }
}

void BoxContainer::expand(std::size_t new_capacity)
{
    value_type* new_items{};

    if (new_capacity == m_capacity)
        return;

    new_items = new value_type[new_capacity];

    for (std::size_t i{}; i < m_size; ++i)
        new_items[i] = m_items[i];

    delete[] m_items;

    m_items = new_items;
    m_capacity = new_capacity;
}

void BoxContainer::add(const value_type &item)
{
    if (m_size == m_capacity)
        expand(m_size + EXPAND_STEPS);

    m_items[m_size] = item;
    ++m_size;
}

bool BoxContainer::remove_item(const value_type &item)
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

std::size_t BoxContainer::remove_all(const value_type &item)
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

void BoxContainer::operator+=(const BoxContainer& src)
{
    if ((m_size + src.m_size) > m_capacity)
        expand(m_size + src.m_size);

    for (std::size_t i{}; i < src.m_size; ++i)
        m_items[m_size + i] = src.m_items[i];

    m_size += src.m_size;
}

void BoxContainer::operator=(const BoxContainer& src)
{
    value_type* new_items{};

    if (this == &src)
        return;

    if (m_capacity != src.m_capacity)
    {
        new_items = new value_type[src.m_capacity];
        delete[] m_items;
        m_items = new_items;
        m_capacity = src.m_capacity;
    }

    for (std::size_t i{}; i < src.m_size; ++i)
        m_items[i] = src.m_items[i];

    m_size = src.m_size;
}

BoxContainer operator+(const BoxContainer& left, const BoxContainer& right)
{
    BoxContainer new_box{ left.size() + right.size() };

    new_box += left;
    new_box += right;

    return new_box;
}