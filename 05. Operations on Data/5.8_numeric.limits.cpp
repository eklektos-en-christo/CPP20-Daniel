//
// Created by Εκλεκτός εν Χριστώ on 26/10/2023.
//

#include <iostream>
#include <limits>           // to get the min, max limit of a type

int main()
{
    std::cout << "Short: " << std::numeric_limits<short>::min() << " to " << std::numeric_limits<short>::max() << '\n';

    std::cout << "Int: " << std::numeric_limits<int>::min() << " to " << std::numeric_limits<int>::max() << '\n';

    std::cout << "Float: " << std::numeric_limits<float>::min() << " to " << std::numeric_limits<float>::max() << '\n';

    std::cout << "Double: " << std::numeric_limits<double>::min() << " to " << std::numeric_limits<double>::max() << '\n';

    std::cout << "Unsigned Short: " << std::numeric_limits<unsigned short>::min() << " to " << std::numeric_limits<unsigned short>::max() << '\n';

    std::cout << "Unsigned Int: " << std::numeric_limits<unsigned int>::min() << " to " << std::numeric_limits<unsigned int>::max() << '\n';

    return 0;
}