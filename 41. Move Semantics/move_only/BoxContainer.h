//
// Created by Εκλεκτός εν Χριστώ on 6/27/24.
//

#ifndef PRACTICE_BOXCONTAINER_H
#define PRACTICE_BOXCONTAINER_H

#include <iostream>

// move only class/type
template <class T>
class BoxContainer
{
    static const std::size_t DEFAULT_CAPACITY{ 30 };
    static const std::size_t EXPAND_STEPS{ 5 };

public:
    explicit BoxContainer(std::size_t capacity=DEFAULT_CAPACITY);

    // deleted copy ctor and assignment
    BoxContainer(const BoxContainer<T>& src) = delete;
    BoxContainer& operator=(const BoxContainer<T>& src) = delete;
    BoxContainer(BoxContainer&& src) noexcept;
    BoxContainer& operator=(BoxContainer&& src) noexcept;
    void operator+=(const BoxContainer<T>& src);

    ~BoxContainer();
    [[nodiscard]] std::size_t size() const { return m_size; }
    [[nodiscard]] std::size_t capacity() const { return m_capacity; }
    void add(const T& item);
    bool remove_item(const T& item);
    std::size_t remove_all(const T& item);
    T get_item(std::size_t index) { return m_items[index]; }

private:
    void expand(std::size_t new_capacity);
    void invalidate() { m_items = nullptr; m_size = 0; m_capacity = 0; }

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
BoxContainer<T>::BoxContainer(BoxContainer<T>&& src) noexcept
{
    // self assignment check
    if (this == &src)
        return;

    m_items = src.m_items;      // steal data, dest object owns the memory of src now
    m_size = src.m_size;
    m_capacity = src.m_capacity;

    src.invalidate();           // necessary to set the src object null/empty

    std::cout << "Moving successful\n";
}

// move assignment
template <class T>
BoxContainer<T>& BoxContainer<T>::operator=(BoxContainer<T>&& src) noexcept
{
    if (this == &src)
        return *this;

    m_items = src.m_items;
    m_size = src.m_size;
    m_capacity = src.m_capacity;

    src.invalidate();

    std::cout << "Move assign successful\n";

    return *this;
}

template <class T>
BoxContainer<T>::~BoxContainer()
{
    std::cout << "BoxContainer destroyed with size: " << m_size << '\n';
    delete[] m_items;
}

template <class T>
void BoxContainer<T>::expand(std::size_t new_capacity)
{
    if (new_capacity == m_capacity)
        return;

    T* new_items = new T[new_capacity];

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
BoxContainer<T> operator+(const BoxContainer<T>& left, const BoxContainer<T>& right)
{
    BoxContainer<T> new_box{ left.size() + right.size() };

    new_box += left;
    new_box += right;

    return new_box;
}

template <class T>
std::ostream& operator<<(std::ostream& out, BoxContainer<T>& operand)
{
    for (std::size_t i{0}; i < operand.size(); ++i)
        out << operand.get_item(i) << ' ';
    return out;
}

#endif //PRACTICE_BOXCONTAINER_H
