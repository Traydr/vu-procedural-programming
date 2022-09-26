#include <iostream>

// Description of task
// Write a C++ program to find whether a given year is a leap year or not.

bool tryAgain() {
    char answer;
    std::cout << "Would you like to try again? (y)\n";
    std::cin >> answer;
    return answer == 'y';
}


int main() {
    int year{0};

    do {
        std::cout << "Please enter a year\n";
        std::cin >> year;

        // This calculation is according to Microsoft Office docs
        // https://learn.microsoft.com/en-us/office/troubleshoot/excel/determine-a-leap-year
        if (year % 4 == 0) {
            if (year % 100 == 0) {
                if (year % 400 == 0) {
                    std::cout << "It is a leap year!\n";
                } else {
                    std::cout << "It is not a leap year!\n";
                }
            } else {
                std::cout << "It is a leap year!\n";
            }
        } else {
            std::cout << "It is not a leap year!\n";
        }
    } while (tryAgain());
    return 0;
}
