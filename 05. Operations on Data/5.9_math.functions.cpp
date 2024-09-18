//
// Created by Εκλεκτός εν Χριστώ on 08/11/2023.
//

#include <iostream>
#include <cmath>

int main()
{
    double weight{ 2.8 };

    std::cout << "weight rounded to floor: " << std::floor(weight) << '\n';
    std::cout << "weight rounded to ceiling : " << std::ceil(weight) << '\n';

    double savings{ -200 };

    std::cout << "Abs. value of weight: " << std::abs(weight) << '\n';
    std::cout << "Abs. value of savings: " << std::abs(savings) << '\n';

    std::cout << "Exponential of 10: " << std::exp(10) << '\n';

    std::cout << "5 raised to the power of 3: " << std::pow(5, 3) << '\n';

    std::cout << "log of 10000 is: " << std::log10(10000) << '\n';

    std::cout << "square root of 64 is: " << std::sqrt(64) << '\n';

    std::cout << "round value of 2.5: " << std::round(2.5) << '\n';
    std::cout << "round value of 2.4: " << std::round(2.4) << '\n';

    return 0;
}