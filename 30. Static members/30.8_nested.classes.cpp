//
// Created by Εκλεκτός εν Χριστώ on 4/7/24.
//

/*
 * nested classes - classes inside the classes
 *
 * private specified nested class can't be accessed outside of the outer class
 * outer class can't access the private members of inner class
 * inner can access private member of the outer class
 * inner can access static members of outer
 * inner can't access member variables without going through an object of outer
 * static members from outer can be accessed directly in the inner
 */

#include <iostream>

class Outer
{
public:
    Outer(int i, double d) : integer{ i }, floating{ d } {}
    Outer() : Outer{0, 0.0} {}
    ~Outer() = default;

    void get_inner()
    {
        Inner i1{ 2.6 };
        std::cout << "Inner Inside the Outer : " << i1.get_inner() << '\n';

        // passing the current instance of outer - inner can access private members
        // of outer now
        i1.get_outer(this);
    }

private:
    int integer{};
    double floating{};
    inline static int stat_int{ 60 };

    class Inner
    {
    public:
        explicit Inner(double inner_param);
        ~Inner() = default;
        double get_inner() const { return inner; }

        void get_outer(Outer* outer)
        {
            std::cout << "Inside the inner : " << outer->integer << ", "
            << outer->floating << '\n';
            std::cout << "static from outer : " << stat_int << '\n';
        }

    private:
        double inner{};
    };
};

// way to access the nested class
Outer::Inner::Inner(double inner_param) : inner{ inner_param }
{
}

int main()
{
    Outer outer{ 2222, 2.2222 };
    outer.get_inner();


    return 0;
}