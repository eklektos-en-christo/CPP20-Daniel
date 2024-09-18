//
// Created by Εκλεκτός εν Χριστώ on 08/02/2024.
//

/*
 * using enum - instead of qualifying enumerator with enum class, we can use the
 * enumerator directly without having to specify the enum class using ::
 *
 * using enum enum_name;
 */

#include <iostream>
#include <string_view>

enum class Month
{
    Jan = 1,
    Feb,
    Mar,
    Apr,
    May,
    Jun,
    Jul,
    Aug,
    Sep,
    Oct,
    Nov,
    Dec
};

std::string_view enum_to_string(Month month)
{
    switch (month)
    {
        // not working on this system, clang doesn't not support using enum
        /*using enum Month;*/

        case Month::Jan : return "January";
        case Month::Feb : return "February";
        case Month::Mar : return "March";
        /*
         *
         *
         *
         *
         */
        default : "????";
    }

    return "None";
}

int main()
{
    Month month{ Month::Feb };
    std::cout << enum_to_string(month) << '\n';

    return 0;
}