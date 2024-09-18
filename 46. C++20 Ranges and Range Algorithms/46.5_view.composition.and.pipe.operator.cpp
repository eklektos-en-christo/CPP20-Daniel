//
// Created by Εκλεκτός εν Χριστώ on 8/19/24.
//

/*
 * view composition - passing data from one view to another view and output might be another view, it
 * is also called raw function composition
 *
 * pipe operator - it can be used to use the output of one view as an input to another view, like in
 * linux
 *
 * pipe operator is more elegant than view composition, both do the same job
 */

#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>

void print_view(auto view)
{
    for (auto element : view)
        std::cout << element << ' ';
    std::cout << '\n';
}

int main()
{
    std::vector<int> vector{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    print_view(vector);

    auto is_even{ [](int n){ return n % 2 == 0; } };

    // raw function composition/view composition
    // first filter the even data in vector
    // then use that filtered view to transform and square it
    // filter is a view and that output is used as an input to the transform view
    auto raw_func_comp{
        std::views::transform(std::views::filter(vector, is_even),
                              [](int n){ return n *= n; })
    };

    // final output view of the transform is used as an input to the print function
    print_view(raw_func_comp);

    // another syntax for view composition
    auto pipe_output
    {
        /*vector as an input to filter and filter output as an input to transform*/
        vector | std::views::filter(is_even) | std::views::transform([](int n){ return n *= n; })
    };

    print_view(pipe_output);

    std::unordered_map<std::string, int> students{ {"leon", 22},
                                                   {"john", 28},
                                                   {"dan", 20},
                                                   {"lucifer", 18},
                                                   {"stella", 30}};

    std::map<std::string, int> students_map{ {"leon", 22},
                                                   {"john", 28},
                                                   {"dan", 20},
                                                   {"lucifer", 18},
                                                   {"stella", 30}};

    auto names_only{ students | std::views::keys };

    std::ranges::copy(names_only, std::ostream_iterator<std::string>(std::cout, " "));

    // unordered map doesn't have reverse iterator, so error
    /*std::ranges::copy(std::views::keys(students) | std::views::reverse, std::ostream_iterator<std::string>(std::cout, " "));*/

    std::cout << '\n';
    std::ranges::copy(std::views::keys(students_map) | std::views::reverse, std::ostream_iterator<std::string>(std::cout, " "));

    // logic to compare the first character of a name in students_map
    auto before_m{ [](const std::string& str){
        return (static_cast<unsigned char>(str[0])) < (static_cast<unsigned char>('m'));
    }};

    std::cout << '\n';

    // take the keys from students_map and then filter the keys that are less than 'm',
    // then print them on the output stream
    std::ranges::copy(students_map | std::views::keys | std::views::filter(before_m),
                      std::ostream_iterator<std::string>(std::cout, " "));

    return 0;
}