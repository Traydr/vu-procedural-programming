#include <iostream>

// Description of task
// Write a C++ program to find whether a given year is a leap year or not.

bool tryAgain() {
    char answer;
    std::cout << "Would you like to try again? (y)\n";
    std::cin >> answer;
    return answer == 'y';
}

int read_int() {
    int input{0};
    bool valid{false};

    do {
        std::cin >> input;
        if (std::cin.good()) {
            valid = true;
        } else {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Invalid input; please re-enter\n";
        }
    } while (!valid);

    return input;
}

int main() {
    int year{0};

    do {
        std::cout << "Please enter a year\n";
        year = read_int();

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
