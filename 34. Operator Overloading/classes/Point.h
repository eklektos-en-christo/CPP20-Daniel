//
// Created by Εκλεκτός εν Χριστώ on 4/13/24.
//

#ifndef PRACTICE_POINT_H
#define PRACTICE_POINT_H

class Number;
class Car;

#include <iostream>
#include <cassert>

    class Point {
    public:
        Point() = default;

        Point(double x, double y, int data);
        Point(const Number& num);

        void print_info() const { std::cout << m_x << ", " << m_y << '\n'; }

        ~Point();

        // 1st argument is implicit, second is the right side operand
        // const Point - to avoid the modifying of source object
        // + is binary operator, so 1 parameter is needed for 2nd operand
        // commented out, otherwise call to operator+ will be ambiguous, 2 overloads are preset in this
        // file for operator+, one is a member, other is a non member
        // 1st argument is implicit object and 2nd is the index
        // & - to be able to change the m_x and m_y
        double &operator[](std::size_t index) {
            // dynamic assert for runtime checking of index
            assert((index == 0) || (index == 1));
            return (index == 0) ? m_x : m_y;
        }

        /*Point operator+(const Point& right) const
        {
            // addition logic inside overloaded operator+
            std::cout << "Member operator+ called!\n";
            return Point{ m_x + right.m_x, m_y + right.m_y };
        }*/


        // << as a member function
        // left operand will be the point class and right will be the ostream class - awkward
        std::ostream &operator<<(std::ostream &os) const {
            // printing the point to the os object which will be printed on the console
            // point output is written to the os object
            os << "Point : [" << m_x << ", " << m_y << ']' << '\n';
            std::cout << "Member operator<< called\n";

            // for operator chaining
            return os;
        }

        Point(const Point& right)
        {
            if (this != &right)
            {
                delete point_data;
                point_data = new int{ *(right.point_data) };
                m_x = right.m_x;
                m_y = right.m_y;
            }
            std::cout << "copy constructor called\n";
        }

        // copy assignment operator - deep copy
        // return by & to support chained copy assignment
        Point& operator=(const Point& right)
        {
            // self assignment check
            if (this != &right)
            {
                // previously pointed data should be released, otherwise memory leak
                delete point_data;

                m_x = right.m_x;
                m_y = right.m_y;

                // create new memory and copy the data from right operand to left - deep copy
                point_data = new int{ *(right.point_data) };
            }

            std::cout << "copy assignment for Point called\n";

            // return an object, not the address of implicit object, so * is used
            // Point& will bind to the implicit object returned by *this
            // then we can use that object in chain assignments
            return *this;
        }


        friend Point operator+(const Point &left, const Point &right);
        friend Point operator-(const Point &left, const Point &right);
        friend Point &operator+=(Point &left, const Point &right);
        friend Point &operator-=(Point &left, const Point &right);

        // 2 params required - function is not a member function, so implicit object is not present
        friend std::ostream &operator<<(std::ostream &os, const Point &p);

        // point is taken by non const reference, we want to make changes when user inputs the data
        friend std::istream &operator>>(std::istream &is, Point &p);

        // implementing operator++ as a member, operand is the implicit object here
        // commented out - defined a non member ++ below
        /*void operator++()
        {
            ++m_x;
            ++m_y;
        }*/

        friend void operator++(Point& operand);

        // int - necessary to differentiate the postfix from prefix
        // postfix ++ as a member
        // returned type can be set according to the need
        /*const Point operator++(int)
        {
            // making a copy of the current object
            Point local_point{ *this };

            // current object is incremented and its copy is returned which is not incremented
            // but current object is changed, changes will reflect after the evaluation of object
            // in a statement
            // statement below calls the prefix version to increment the current Point(this)
            ++(*this);
            return local_point;
        }*/

        void operator--()
        {
            --m_x;
            --m_y;
        }

        Point operator--(int)
        {
            Point local_object{ *this };
            --(*this);
            return local_object;
        }

        // copy a Car object to Point
        // void - chained assignments are not supported
        void operator=(const Car& right_car);

        void operator=(const Number& n);

    private:
        double m_x{};
        double m_y{};
        int* point_data{ nullptr };
    };

// postfix ++ as a non member, int necessary here also to distinguish
// not necessary to declare as a friend of the Point, not accessing any private members, only
// calling the prefix operator
const Point operator++(Point& operand, int);

// non member accessing private members of Point - friend of the Point class
// using inline to constrain the definition to this TU only
inline Point operator+(const Point& left, const Point& right)
{
    // std::cout << "Non member operator+ called!\n";
    /*return Point{ left.m_x + right.m_x, left.m_y + right.m_y };*/

    // memberwise copy here, we want to return this object after the + operation
    Point p(left);

    // reusing the += overload, addition operation will return a new point object
    return p+= right;
}

inline Point operator-(const Point& left, const Point& right)
{
    /*return Point{left.m_x - right.m_x, left.m_y - right.m_y};*/

    Point p(left);

    // reusing the -= overload
    return p -= right;
}

inline Point& operator+=(Point& left, const Point& right)
{
    // += works here, underlying type is double, += is defined already for fundamental types
    left.m_x += right.m_x;
    left.m_y += right.m_y;
    return left;
}

inline Point& operator-=(Point& left, const Point& right)
{
    left.m_x -= right.m_x;
    left.m_y -= right.m_y;
    return left;
}

// standalone friend operator<<
inline std::ostream& operator<<(std::ostream& os, const Point& p)
{
    os << "Point : [" << p.m_x << ", " << p.m_y << ", " << *(p.point_data) << ']';
    return os;
}

// return the input stream by ref. for operator chaining
inline std::istream& operator>>(std::istream& is, Point& p)
{
    std::cout << "Enter the x coordinate: ";
    is >> p.m_x;

    std::cout << "Enter the y coordinate: ";
    is >> p.m_y;

    return is;
}

inline void operator++(Point& operand)
{
    ++operand.m_x;
    ++operand.m_y;
    /*std::cout << "Non member ++ called\n";*/
}

inline const Point operator++(Point& operand, int)
{
    Point local_object{ operand };
    // this call the prefix version
    ++operand;
    return local_object;
}

#endif //PRACTICE_POINT_H
