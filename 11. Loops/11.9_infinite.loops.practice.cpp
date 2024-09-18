//
// Created by Εκλεκτός εν Χριστώ on 18/12/2023.
//

#include <iostream>

int main()
{
    std::cout << "-------CALCULATOR-------\n";

    char operation{};
    double operand1{};
    double operand2{};
    bool quit{ false };

    while (!quit)
    {
        std::cout << "SUPPORTED OPERATIONS ARE +, -, * AND /\n";
        std::cout << "ENTER ANY ONE : ";
        std::cin >> operation;

        if ((operation != '+') && (operation != '-') && (operation != '*') && (operation != '/'))
        {
            std::cout << "UNSUPPORTED OPERATION!\n";
            std::cout << "------------------------\n";
            continue;
        }

        std::cout << "VALUE 1 : ";
        std::cin >> operand1;
        std::cout << "VALUE 2 : ";
        std::cin >> operand2;

        switch (operation) {
            case '+' :
                std::cout << "ADD(" << operand1 << " + " << operand2 << ") = ";
                std::cout << operand1 + operand2 << '\n';
                break;

            case '-' :
                std::cout << "SUB(" << operand1 << " - " << operand2 << ") = ";
                std::cout << operand1 - operand2 << '\n';
                break;

            case '*' :
                std::cout << "MUL(" << operand1 << " x " << operand2 << ") = ";
                std::cout << operand1 * operand2 << '\n';
                break;

            case '/' :
                std::cout << "DIV(" << operand1 << " / " << operand2 << ") = ";
                std::cout << operand1 / operand2 << '\n';
                break;
        }

        char stop{};
        std::cout << "WANNA QUIT? (Y/N) : ";
        std::cin >> stop;

        if (stop == 'Y' || stop == 'y')
        {
            quit = true;
            std::cout << "GOOD BYE!\n";
        }
        std::cout << "------------------------\n";
    }

    return 0;
}