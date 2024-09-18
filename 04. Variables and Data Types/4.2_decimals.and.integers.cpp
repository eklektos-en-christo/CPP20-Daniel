//
// Created by Εκλεκτός εν Χριστώ on 12/10/2023.
//

#include <iostream>

int main()
{
    // contains garbage value
    int elephant_count;

    // initializes to 0
    int lion_count{};

    // braced initialization - initialized to 10
    int dog_count{ 10 };

    // braced initialization -  initialized to 15
    int cat_count{ 15 };

    // using the expression as initializer
    int domesticated_count{ dog_count + cat_count };

    // wouldn't compile, can't initialize an int with the decimal point in braced initialization
    /*int fractional_data{ 2.1 };*/

    // functional initialization
    int cow_count(2);
    int rat_count(10);
    int animal_count (cow_count + rat_count);

    // works in fractional initialization but data is lost, fraction value is chopped off
    int narrowing_conversion(2.11);
    std::cout << narrowing_conversion << '\n';

    // assignment initialization
    int tree_count = 17;
    int car_count = 22;
    int car_plus_tree = tree_count + car_count;

    std::cout << car_plus_tree << '\n';

    // works with assignment but data is lost, fraction data is chopped off
    int narrow_assignment = 2.2323;
    std::cout << narrow_assignment << '\n';

    // checking the size of variables
    std::cout << sizeof(int) << '\n';
    std::cout << sizeof(car_plus_tree) << '\n';
    std::cout << sizeof(char16_t [20]) << '\n';


    return 0;
}