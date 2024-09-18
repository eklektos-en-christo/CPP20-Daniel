//
// Created by Εκλεκτός εν Χριστώ on 6/25/24.
//

/*
 * catch(...) - can catch all kind of exceptions, it should be put at the end of all catch
 * handlers, otherwise it will catch all other exceptions which are not meant to be handled
 * by this block, we can also rethrow exceptions from catch all block
 */

#include <iostream>

void do_something(std::size_t i)
{
    if (i == 2)
        throw 2;
    if (i == 3)
        throw "i is 5";
    if (i == 7);
        throw std::string("i is 7");
}

int main()
{
        try
        {
            for (std::size_t i{2}; i < 10; ++i)
            {
                try
                {
                    do_something(i);
                }
                catch (int ex)
                {
                    std::cout << "int exception is handled: " << ex << '\n';
                }
                catch (...) {
                    std::cout << "(inner) - some exceptions have been caught\n";
                    throw;
                }
            }
        }
        catch (const char* ex)
        {
            std::cout << "const char* exception is handled: " << ex << '\n';
        }
        catch (...)
        {
            std::cout << "(outer) - All exceptions have been handled\n";
        }

    return 0;
}