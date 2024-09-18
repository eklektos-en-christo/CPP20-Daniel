//
// Created by Εκλεκτός εν Χριστώ on 6/27/24.
//

#ifndef PRACTICE_BOXCONTAINER_H
#define PRACTICE_BOXCONTAINER_H

#include "StreamInsertable.h"

class BoxContainer : public StreamInsertable
{
    using value_type = int;
    static const std::size_t DEFAULT_CAPACITY{ 30 };
    static const std::size_t EXPAND_STEPS{ 5 };

public:
    BoxContainer(std::size_t capacity=DEFAULT_CAPACITY);
    BoxContainer(const BoxContainer& src);
    virtual ~BoxContainer();

    virtual void stream_insert(std::ostream& out) const override;

    std::size_t size() const { return m_size; }
    std::size_t capacity() const { return m_capacity; }

    void dummy_init()
    {
        for (std::size_t i{}; i < 10; ++i)
            m_items[i] = i + 12;

        m_size = 10;
    }

    void add(const value_type& item);

    bool remove_item(const value_type& item);
    std::size_t remove_all(const value_type& item);

    void operator+=(const BoxContainer& src);
    void operator=(const BoxContainer& src);

private:
    void expand(std::size_t new_capacity);

private:
    value_type* m_items{};
    std::size_t m_size{};
    std::size_t m_capacity{};
};

BoxContainer operator+(const BoxContainer& left, const BoxContainer& right);

#endif //PRACTICE_BOXCONTAINER_H
