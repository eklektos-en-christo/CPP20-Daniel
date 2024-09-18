//
// Created by Εκλεκτός εν Χριστώ on 3/8/24.
//

/*
 * struct : same as class but struct has public member by default, one common use is when we need
 * all data members public without the member functions in a struct
 */

#include <iostream>
#include <string>

struct DogStruct
{
public:
    Dog() = default;
    ~Dog()= default;

private:
    std::string m_name{};
    std::string m_breed{};
    int* p_age{ nullptr };
};

class DogClass
{
    DogClass() = default;
    ~DogClass()= default;

    std::string m_name{};
    std::string m_breed{};
    int* p_age{ nullptr };
};

int main()
{
    // public members in the struct
    DogStruct d1;

    // constructor is private, so no object creation possible
    // DogClass d2;

    return 0;
}