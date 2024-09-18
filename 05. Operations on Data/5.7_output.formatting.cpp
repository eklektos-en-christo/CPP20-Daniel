//
// Created by Εκλεκτός εν Χριστώ on 26/10/2023.
//

#include <iostream>
#include <iomanip>

int main()
{
    // for a new line
    std::cout << "Hello" << std::endl;

    // for a new line
    std::cout << "Hello\n";

    // to empty the output buffer and sent the output to the stream
    std::cout << "This is a message!" << '\n' << std::flush;

    // setting the width of a word - total width headers the word and remaining spaces
    std::cout << std::setw(10) << "Name" << std::setw(10) << "Class" << '\n';
    std::cout << std::setw(10) << "Leon" << std::setw(10) << "1st" << '\n';
    std::cout << std::setw(10) << "Jake" << std::setw(10) << "3rd" << '\n';
    std::cout << std::setw(10) << "Sean" << std::setw(10) << "2nd" << '\n';

    // left justified output, right justified is default
    std::cout << std::left;
    std::cout << std::setw(10) << "Name" << std::setw(10) << "Class" << '\n';
    std::cout << std::setw(10) << "Leon" << std::setw(10) << "1st" << '\n';
    std::cout << std::setw(10) << "Jake" << std::setw(10) << "3rd" << '\n';
    std::cout << std::setw(10) << "Sean" << std::setw(10) << "2nd" << '\n';

    // right justification, - sign goes with the data
    std::cout << std::right;
    std::cout << std::setw(10) << -242.4234 << '\n';
    std::cout << std::setw(10) << -242.4234 << '\n';

    // internal justification, - sign remains on the left
    std::cout << std::internal;
    std::cout << std::setw(10) << -242.4234 << '\n';
    std::cout << std::setw(10) << -242.4234 << '\n';

    // setting the empty spaces to '
    std::cout << std::setfill('\'');
    std::cout << std::setw(20) << "Name" << std::setw(20) << "Class" << '\n';
    std::cout << std::setw(20) << "Leon" << std::setw(20) << "1st" << '\n';
    std::cout << std::setw(20) << "Jake" << std::setw(20) << "3rd" << '\n';
    std::cout << std::setw(20) << "Sean" << std::setw(20) << "2nd" << '\n';

    // display the boolean values as true/false instead of 1/0
    std::cout << std::boolalpha;
    std::cout << true << "  " << false << '\n';

    // disable the boolalpha
    std::cout << std::noboolalpha;
    std::cout << true << "  " << false << '\n';

    // force the stream to show positive numbers with sign
    std::cout << std::showpos;
    std::cout << 2.233 << '\n';
    std::cout << 32329 << '\n';

    // don't show the + sign of positive numbers
    std::cout << std::noshowpos;
    std::cout << 2.233 << '\n';
    std::cout << 32329 << '\n';

    // show the integers in different base systems
    std::cout << std::dec;
    std::cout << 125353 << '\n';
    std::cout << std::hex;
    std::cout << 125353 << '\n';
    std::cout << std::oct;
    std::cout << 125353 << '\n';

    // show the text in uppercase
    std::cout << std::uppercase;
    std::cout << std::hex;
    std::cout << 125353 << '\n';

    // show in scientific notation
    std::cout << std::scientific;
    std::cout << 2.3342 << '\n';
    std::cout << 323.3857239572985702 << '\n';

    // show in fixed notation
    std::cout << std::fixed;
    std::cout << 2.66 << '\n';
    std::cout << 323.3857239572985702 << '\n';

    // setting the precision
    std::cout << std::setprecision(20);
    std::cout << 2.3342 << '\n';

    // forcing to show the decimal point in the output
    std::cout << std::setprecision(5);
    std::cout << std::showpoint;
    std::cout << 424.0 << '\n';

    // force to show the base of the number
    std::cout << 0x2333 << '\n';
    std::cout << std::showbase;
    std::cout << 0x2333 << '\n';

    return 0;
}