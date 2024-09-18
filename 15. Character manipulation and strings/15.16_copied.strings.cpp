//
// Created by Εκλεκτός εν Χριστώ on 16/01/2024.
//

/*
 *
 */

#include <iostream>
#include <string>

int main()
{
    std::string message{ "PROGRAMMING" };
    std::string message_copy{ message };            // wasted space

    // data() - returns pointer to the std::string
    char* ptr_message{ message.data() };
    char* ptr_message_copy{ message_copy.data() };

    // casting pointer to a void pointer - cout prints the string when using char*
    std::cout << static_cast<void*>(ptr_message) << '\n';
    std::cout << static_cast<void*>(ptr_message_copy) << '\n';

    std::string& message_copy_again{ message };

    char* ptr_mess1{ message.data() };
    char* ptr_mess2{ message_copy_again.data() };

    // c style casting - both pointers are pointing to same string - message
    // no wastage of memory
    std::cout << (void*)ptr_mess1 << '\n';
    std::cout << (void*)ptr_mess2 << '\n';

    return 0;
}