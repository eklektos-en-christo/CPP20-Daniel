//
// Created by Εκλεκτός εν Χριστώ on 7/6/24.
//

/* Class template specialization: are not templates, they are full classes, multiple inclusions of same
 * header in different files will cause ODR errors, one way is to make methods inline and keep them in
 * the same header or define them in different source files
 *
 * specialization are full new class from the existing template classes
 *
 * we can specialize a template for the types by implementing it different for that specific type and
 * let the default template same for other types, the original template is required also for this
 *
 * syntax:
 *
 * template<>
 * class class_name<type>
 * {
 *      definitions and use of that type inside
 * }
 *
 * methods contain in original template and specialization are different, if template defines them and
 * specialization doesn't, then specialization won't have them
 *
 * we can specialize the single methods also, instead the whole class
 */

#include <iostream>
#include <cstring>

// regular class template
template <class T>
class Adder
{
public:
    Adder() = default;
    T add(T a, T b);
    void do_something() { std::cout << "Doing something\n"; }
};

template <class T>
T Adder<T>::add(T a, T b)
{
    std::cout << "Using add() from a regular template instance\n";
    return a + b;
}

// specialized template for char type, <> should be empty and type should be passed to the class
template <>
class Adder <char*>
{
public:
    Adder() = default;
    char* add(char* a, char* b);
};

// template <> is not needed - compiler error
char* Adder<char*>::add(char* a, char* b)
{
    std::cout << "Using add() from a specialized template instance\n";
    return strcat(a, b);
}

int main()
{
    Adder<int> int_adder;
    int_adder.do_something();
    std::cout << int_adder.add(1, 1) << '\n';

    char c1[]{ "Hello" };
    char c2[]{ " World" };

    // won't work, can't add ptrs
    // even if it works, the result won't be what we expect
    /*Adder<char*> char_adder;
    char_adder.add(c1, c2);*/

    // this uses the specialized version of template for char* type
    Adder<char*> char_adder2;

    // can't call this, because it is not present in the specialization
    /*char_adder2.do_something();*/
    std::cout << char_adder2.add(c1, c2) << '\n';

    return 0;
}