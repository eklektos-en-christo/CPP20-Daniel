//
// Created by Εκλεκτός εν Χριστώ on 6/22/24.
//

/*
 * we can nest try blocks, inner block handles the exception of its try block, if no catch is
 * available in nested block then exception is propagated to outer block which can handle
 * that exception
 */

#include <iostream>
#include <string>

void exception_thrower()
{
    throw 'z';
}

void some_func()
{
    for (std::size_t i{0}; i < 15; ++i)
    {
        std::cout << "ITERATION : " << i << '\n';

        try
        {
            if (i == 2)
                throw "Exception thrown for int 2";

            try
            {
                if (i == 6)
                    throw i;

                if (i == 8)
                    throw '8';

                if (i == 10)
                    exception_thrower();

                if (i == 13)
                    throw std::string("std::string thrown for int 13");
            }
            catch (char ex)
            {
                std::cout << "Inner catch(char) handled the exception for: " << ex << '\n';
            }
        }
        catch (const char* ex)
        {
            std::cout << "Outer catch(const char*) handled the exception for: " << ex << '\n';
        }

        catch (std::size_t ex)
        {
            std::cout << "Outer catch(size_t) handled the exception for: " << ex << '\n';
        }
    }
}

int main()
{
    try
    {
        some_func();
    }
    catch (std::string& ex)
    {
        std::cout << "main() catch handled the exception for: " << ex << '\n';
    }

    return 0;
}