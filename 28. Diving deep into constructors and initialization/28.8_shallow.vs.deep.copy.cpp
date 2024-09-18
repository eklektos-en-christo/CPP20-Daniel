//
// Created by Εκλεκτός εν Χριστώ on 4/1/24.
//

/*
 * shallow copy - member wise initialization, even when there are pointers as members, this
 * is the default behavior
 *
 * deep copy - member wise initialization, but separate allocation for pointer members, this
 * is a customized behavior
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
        std::cout << "Object addr. : " << this;
        std::cout << ", fname : " << m_fname << ' ';
        std::cout << ", lname : " << m_lname << ' ';
        std::cout << ", Age : " << *p_age << ' ';
        std::cout << ", Age addr. : " << p_age << '\n';
    }
};

Person::Person(const std::string& fname, const std::string& lname, int age)
        : m_fname{ fname }, m_lname{ lname }, p_age{ new int{age} }
{
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

Person::Person(const Person &src_person)
        : Person{ src_person.get_fname(), src_person.get_lname(), src_person.get_age() }
{
}

int main()
{


    return 0;
}