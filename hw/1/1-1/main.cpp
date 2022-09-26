#include <iostream>

// Description of task
// Write a C++ program that convert a temperature from Centigrade to Fahrenheit.

bool tryAgain() {
    char answer;
    std::cout << "Would you like to try again? (y)\n";
    std::cin >> answer;
    return answer == 'y';
}


int main() {
    int celsius {0};
    int fahrenheit {0};

    do {
        std::cout << "Please enter a temperature in C\n";
        std::cin >> celsius;
        fahrenheit = (celsius * 9) / 5 + 32;
        std::cout << celsius << "C in Fahrenheit is " << fahrenheit << "F\n";
        celsius = 0;
        fahrenheit = 0;
    } while (tryAgain());

    return 0;
}
