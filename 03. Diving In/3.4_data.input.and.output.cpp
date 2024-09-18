//
// Created by Εκλεκτός εν Χριστώ on 10/10/2023.
//

#include <iostream>
#include <string>

int main()
{
    /*
    // printing data
    std::cout << "HELLO\n";
    std::cerr << "Error message : There's a flaw in the code!\n";
    std::clog << "Log message : something happened!\n";
     */

    /*
    // getting data
    int age;
    std::string name{};

    std::cout << "What is your name? : ";
    // data flowing from std::cin to name
    std::cin >> name;
    std::cout << "Please type in your age : ";
    std::cin >> age;

    std::cout << "Hello " << name << ", you're " << age << " years old!\n";

    std::cout << "Please enter your name and age, separated by a space : ";
    std::cin >> name >> age;
    std::cout << "Name : " << name << ", Age : " << age << '\n';
    */

    // getting data with spaces
    std::string full_name{};

    std::cout << "Enter your full name, separated by a space : ";
    std::getline(std::cin, full_name, '\n');
    std::cout << "Your name is : " << full_name << '\n';

    return 0;
}