//
// Created by Εκλεκτός εν Χριστώ on 7/13/24.
//

/*
 * if we pass an object by rvalue reference, it is treated as a lvalue
 * when a rvalue has a name, it becomes a lvalue, in this case the copy semantics are used when the
 * object is assigned or copy constructed
 */

#include <iostream>

class Item
{
    friend std::ostream& operator<<(std::ostream& out, const Item& operand);

public:
    Item() : m_data{ new int }{}
    explicit Item(int value) : m_data{ new int{ value } } {}

    Item(const Item& src) : m_data{ new int }
    {
        std::cout << "Copy ctor called\n";

        *m_data = *(src.m_data);
    }

    Item& operator= (const Item& src)
    {
        std::cout << "Copy assign. called\n";

        if (this != &src)
            *m_data = *(src.m_data);
        return *this;
    }

    Item(Item&& src) noexcept
    {
        std::cout << "Move ctor called\n";

        m_data = src.m_data;
        src.m_data = nullptr;
    }

    Item& operator= (Item&& src) noexcept
    {
        std::cout << "Move assign. called\n";

        if (this != &src)
            m_data = src.m_data;
        src.m_data = nullptr;

        return *this;
    }

private:
    int* m_data{ nullptr };
};

std::ostream& operator<<(std::ostream& out, const Item& operand)
{
    out << *(operand.m_data);
    return out;
}

Item get_value()
{
    return Item{21};
}

// item is a rvalue ref., it can't bind to a lvalue
// it can bind to a rvalue
// after binding to a rvalue, it is treated as lvalue
void do_something(Item&& item)
{
    // item is a lvalue because it has a name, copy semantics used
    Item local_item = item;
}

int main()
{
    // rvalue reference to the temporary 21
    Item&& rvalue_item{ get_value() };

    Item item1;

    // though rvalue_item is a rvalue, it is treated as lvalue
    // because it has a name : rvalue_item
    // lvalue by default calls the copy ctor/assign.
    item1 = rvalue_item;

    // lvalue should be made rvalue to move it to the destination
    item1 = std::move(rvalue_item);

    do_something(std::move(item1));

    return 0;
}