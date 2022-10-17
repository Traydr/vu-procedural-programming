#include <iostream>

// Description of task
// Write a C ++ program to determine if the number entered is even or odd. Use void type functions

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

void isEven(int num) {
    if (num % 2 == 0) {
        std::cout << "Number is even\n";
    } else {
        std::cout << "Number is odd\n";
    }
}

int main() {
    do {
        std::cout << "Enter num\n";
        int x{readInt()};

        isEven(x);
    } while (tryAgain());

    return 0;
}

