//
// Created by Εκλεκτός εν Χριστώ on 3/29/24.
//

/*
 * copy constructors : create new object from an existing object, new object is the copy
 *
 * it should take argument by reference, otherwise infinite calls to copy constructors may happen
 * when the object are passed by value, if there is a dynamic memory allocated in the source
 * object, the dest. object should allocate its own memory, it shouldn't use src. object's dynamic
 * memory
 *
 * use the constructor delegation whenever possible
 */

#include <iostream>
#include <string>

class Person
{
    std::string m_fname{};
    std::string m_lname{};
    int* p_age{};

public:
    Person() = default;
    Person(const std::string& fname, const std::string& lname, int age);
    Person(const std::string& fname, const std::string& lname);
    Person(const std::string& lname);
    ~Person();

    Person(const Person& src_person);

    void set_fname(const std::string& fname) { m_fname = fname; }
    void set_lname(const std::string& lname) { m_lname = lname; }
    void set_age(int age) { *p_age = age; }

    const std::string& get_fname() const { return m_fname; }
    const std::string& get_lname() const { return m_lname; }
    const int get_age() const { return *p_age; }

    void print_person()
    {
        std::cout << "Object addr. : " << this << '\n';
        std::cout << "fname : " << m_fname << '\n';
        std::cout << "lname : " << m_lname << '\n';
        std::cout << "Age : " << *p_age << '\n';
        std::cout << "Age addr. : " << p_age << '\n' << '\n';
    }
};

Person::Person(const std::string& fname, const std::string& lname, int age)
    : m_fname{ fname }, m_lname{ lname }, p_age{ new int{age} }
{
    std::cout << "Main constructor called\n";
}

Person::Person(const std::string& fname, const std::string& lname)
    : Person{ fname, lname, 0 }
{
}

Person::Person(const std::string& lname)
    : Person{"", lname }
{
}

Person::~Person()
{
    delete p_age;
}

// copy constructor - allocate new location for age pointer
/*Person::Person(const Person &src_person)
    : m_fname{ src_person.get_fname() }, m_lname{ src_person.get_lname() },
      p_age{ new int{ src_person.get_age() } }
{
}*/

// instead of calling a copy constructor on copy, we can delegate the responsibility to the
// main constructor through the copy constructor, which will create a new object and also allocate a new location for age
Person::Person(const Person &src_person)
    : Person{ src_person.get_fname(), src_person.get_lname(), src_person.get_age() }
{
}

int main()
{
    Person p1{ "Tyrell", "Wellick", 29 };
    p1.print_person();

    Person p2{ p1 };
    p2.set_age(30);

    // p2 and p1 both accessing the same age - copy constructor copied the address only
    /*p1.print_person();
    p2.print_person();*/

    // copy constructor allocated the new memory for age pointer member
    p2.print_person();

    return 0;
}