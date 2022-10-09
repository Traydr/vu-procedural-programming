#include <iostream>
#include <cmath>

// Description of task
// Write a program in C++ that sums all the natural numbers with each other that are less than the number you entered.
// e.g. (n=7 1+2+3+4+5+6)

bool tryAgain() {
    char answer;
    std::cout << "Would you like to try again? (y)\n";
    std::cin >> answer;
    return answer == 'y';
}

int readInt() {
    int input{0};
    bool valid{false};

    do {
        std::cin >> input;
        if (std::cin.good()) {
            valid = true;
        } else {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Invalid input; please re-enter.\n";
        }
    } while (!valid);

    return input;
}

bool isPrime(long number) {
    if (number <= 1) return false;
    if (number == 2) return true;
    if (number % 2 == 0) return false;

    long boundary = floor(sqrt(number));

    for (long i = 3; i <= boundary; i += 2) if (number % i == 0) return false;

    return true;
}

int main() {
    do {
        std::cout << "Enter a prime number\n";
        int input = readInt();

        if (isPrime(input)) {
            std::cout << input << " is a prime number!\n";
        } else {
            std::cout << input << " is NOT a prime number!\n";
        }
    } while (tryAgain());
    return 0;
}


