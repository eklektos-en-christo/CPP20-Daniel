//
// Created by Εκλεκτός εν Χριστώ on 8/12/24.
//

/*
 * std::queue - elements are inserted from one end and removed from the other end
 *
 * works in FIFO fashion
 *
 *
 */

#include <iostream>
#include <queue>
#include <list>
#include <deque>

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

template <typename T, typename Container = std::deque<T>>
void print_queue(std::queue<T, Container> queue)
{
    std::cout << "Queue: [ ";

    while (!queue.empty())
    {
        std::cout << queue.front() << ' ';
        queue.pop();
    }
    std::cout << ']' << '\n';
}

template <typename T, typename Container = std::deque<T>>
void clear_queue(std::queue<T, Container>& queue)
{
    std::cout << "Clearing the queue...\n";

    while (!queue.empty())
        queue.pop();
}

int main()
{
    std::queue<int> queue1;

    queue1.push(6);
    queue1.push(8);
    queue1.push(4);
    queue1.push(1);
    queue1.push(3);

    // FIFO fashion
    print_queue(queue1);

    std::cout << queue1.front() << ' ' << queue1.back() << '\n';

    // both return a reference to the element - modifiable
    queue1.front() = 66;
    queue1.back() = 33;

    print_queue(queue1);

    queue1.pop();

    print_queue(queue1);

    // using reference for clearing
    clear_queue(queue1);
    std::cout << "Size becomes: " << queue1.size() << '\n';

    print_queue(queue1);

    std::queue<Book> books;

    // storing a custom type in queue
    books.push({2021, "book1"});
    books.push({1992, "book2"});
    books.push({1886, "book3"});

    // FIFO fashion
    print_queue(books);

    // use std::list as an underlying sequence container
    std::queue<int, std::list<int>> list_queue;

    list_queue.push(2);
    list_queue.push(3);

    print_queue(list_queue);

    return 0;
}