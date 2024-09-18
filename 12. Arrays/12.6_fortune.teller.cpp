//
// Created by Εκλεκτός εν Χριστώ on 20/12/2023.
//

#include <iostream>
#include <ctime>

int main()
{
    std::srand(std::time(0));

    char pred0[] { "What is wrong with you?" };
    char pred1[] { "You will go to hell" };
    char pred2[] { "I don't know you" };
    char pred3[] { "God damn you" };
    char pred4[] { "I will kill you" };
    char pred5[] { "Go to sleep please" };
    char pred6[] { "Listen to me" };
    char pred7[] { "I'm a serial killer" };
    char pred8[] { "Drink my blood" };
    char pred9[] { "Go to a dog" };

    bool quit{ false };

    const int max_length { 20 };
    char name[max_length] {};

    std::cout << "What is your name dear? : ";
    std::cin.getline(name, max_length);

    while (!quit)
    {
        std::cout << "Oh dear " << name << ", I see, ";

        size_t random_num = static_cast<size_t>(std::rand() % 11);

        switch (random_num)
        {
            case 0 : std::cout << pred0 << '\n'; break;
            case 1 : std::cout << pred1 << '\n'; break;
            case 2 : std::cout << pred2 << '\n'; break;
            case 3 : std::cout << pred3 << '\n'; break;
            case 4 : std::cout << pred4 << '\n'; break;
            case 5 : std::cout << pred5 << '\n'; break;
            case 6 : std::cout << pred6 << '\n'; break;
            case 7 : std::cout << pred7 << '\n'; break;
            case 8 : std::cout << pred8 << '\n'; break;
            case 9 : std::cout << pred9 << '\n'; break;

            default : std::cout << "Okay! I don't see anything" << '\n';
        }

        char try_again;
        std::cout << "Do you want me to try again? (Y/N) : ";
        std::cin >> try_again;

        quit = ((try_again == 'Y') || (try_again == 'y')) ? false : true;

    }

    std::cout << "That's all I have for you today!" << '\n';

    return 0;
}