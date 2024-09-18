//
// Created by Εκλεκτός εν Χριστώ on 8/12/24.
//

/*
 * std::priority_queue - works the same as std::queue but elements are removed by the higher priority
 *
 * priority is decided by looking at the comparison operator of the element type, elements are also
 * ordered on the basis of priority
 *
 * std::vector is default underlying container for priority queue
 */

#include <iostream>
#include <queue>

template <typename T>
void print_queue(std::priority_queue<T> queue)
{
    std::cout << "Queue: [ ";

    while (!queue.empty())
    {
        std::cout << queue.top() << ' ';
        queue.pop();
    }
    std::cout << ']' << '\n';
}

// std::less<typename Container::value_type> - the comparator uses the same type as the
// underlying Container(vector) has
template <typename T, typename Container = std::vector<T>,
        typename Compare = std::less<typename Container::value_type>>
void print_queue(std::priority_queue<T, Container, Compare> queue)
{
    std::cout << "Queue: [ ";

    while (!queue.empty())
    {
        std::cout << queue.top() << ' ';
        queue.pop();
    }
    std::cout << ']' << '\n';
}

template <typename T, typename Container = std::vector<T>,
        typename Compare = std::less<typename Container::value_type>>
void clear_queue(std::priority_queue<T>& queue)
{
    std::cout << "Clearing the queue...\n";

    while (!queue.empty())
    {
        std::cout << queue.top() << ' ';
        queue.pop();
    }

    std::cout << '\n';
    print_queue(queue);
}

int main()
{
    std::priority_queue<int> priority_queue1;

    priority_queue1.push(2);
    priority_queue1.push(6);
    priority_queue1.push(3);
    priority_queue1.push(1);

    // std::less is the default comparator
    // larger element has the higher priority
    // so larger will go out first
    print_queue(priority_queue1);

    // error: top returns a const reference, non modifiable
    /*priority_queue1.top() = 2;*/

    // highest priority element will be removed first
    priority_queue1.pop();
    print_queue(priority_queue1);

    clear_queue(priority_queue1);

    // explicitly specifying the underlying container and comparator
    std::priority_queue<int, std::vector<int>, std::greater<int>> p_queue_v;

    p_queue_v.push(1);
    p_queue_v.push(8);

    print_queue(p_queue_v);

    auto compare{ [](int left, int right){ return left < right; } };

    std::priority_queue<int, std::vector<int>, decltype(compare)> functor_queue{ compare };

    functor_queue.push(2);
    functor_queue.push(8);
    functor_queue.push(3);

    print_queue(functor_queue);

    return 0;
}