//
// Created by Εκλεκτός εν Χριστώ on 3/31/24.
//

/*
 * putting objects in an array is going to create copies of the objects in the array
 *
 * range based for loop is also going to create copies of the objects in the array
 * to avoid copies in the range based loop, take the objects by reference &
 *
 * regular loops don't make copies of the objects
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

// copy constructor - allocate new location for age pointer
/*Person::Person(const Person &src_person)
    : m_fname{ src_person.get_fname() }, m_lname{ src_person.get_lname() },
      p_age{ new int{ src_person.get_age() } }
{
}*/

Person::Person(const Person &src_person)
        : Person{ src_person.get_fname(), src_person.get_lname(), src_person.get_age() }
{
    std::cout << "Copy constructor called for : " << src_person.get_fname() << '\n';
}


int main()
{
    Person p1{"Johnny", "Depp", 33};
    Person p2{"Honny", "Sepp", 30};
    Person p3{"Tony", "Den", 32};

    p1.print_person();
    p2.print_person();
    p3.print_person();

    std::cout << "-----------\n";

    // an array of person objects - copy constructor called 3 times to copy the objects
    // into the array
    Person person_array[]{ p1, p2, p3 };

    std::cout << "-----------\n";

    for (std::size_t i{0}; i < std::size(person_array); ++i)
    {
        // copies
        person_array[i].print_person();
    }

    std::cout << "-----------\n";

    // copies created in the range based loop
    for (Person p : person_array)
    {
        p.print_person();
    }

    return 0;
}