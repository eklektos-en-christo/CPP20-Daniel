//
// Created by Εκλεκτός εν Χριστώ on 8/11/24.
//

/*
 * std::stack - not a container, an interface built on top of a few possible sequence containers
 *
 * works in LIFO fashion - last in first out
 *
 * supports back, push back and pop back operations
 *
 * std::deque is the underlying container used by std::stack by default, vector and list can also be
 * specified as a second template argument in declaration of the stack
 */

#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <deque>

template <typename T>
void print_stack(std::stack<T> stack)
{
    std::cout << "Stack: [ ";

    while (!stack.empty())
    {
        std::cout << stack.top() << ' ';
        stack.pop();
    }
    std::cout << ']' << '\n';
}

// default container is deque if not provided
// vector or list can alse be provided as an underlying container
template <typename T, typename Container = std::deque<T>>
void print_vstack(std::stack<T, Container> vstack)
{
    std::cout << "Stack: [ ";

    while (!vstack.empty())
    {
        std::cout << vstack.top() << ' ';
        vstack.pop();
    }
    std::cout << ']' << '\n';
}

template <typename T>
void clear_stack(std::stack<T>& stack)
{
    std::cout << "Clearing the stack...\n";

    while (!stack.empty())
        stack.pop();
}

template <typename T, typename Container = std::deque<T>>
void clear_vstack(std::stack<T, Container>& vstack)
{
    std::cout << "Clearing the stack...\n";

    while (!vstack.empty())
        vstack.pop();
}

int main()
{
    std::stack<int> stack1;

    print_stack(stack1);

    stack1.push(1);
    stack1.push(2);
    stack1.push(3);

    print_stack(stack1);

    std::cout << "Top: " << stack1.top() << '\n';

    // top returns a reference
    stack1.top() = 5;

    print_stack(stack1);

    stack1.pop();

    print_stack(stack1);

    clear_stack(stack1);

    // empty stack
    print_stack(stack1);

    // use vector as the underlying sequence container
    std::stack<int, std::vector<int>> vector_stack;

    vector_stack.push(11);
    vector_stack.push(22);
    vector_stack.push(33);

    // error - underlying seq. container is a vector and stack uses deque
    // print_stack should be able to receive a stack with an underlying vector
    /*print_stack(vector_stack);*/

    print_vstack(vector_stack);
    clear_vstack(vector_stack);
    print_vstack(vector_stack);

    return 0;
}