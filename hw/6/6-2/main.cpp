#include <iostream>
#include <cmath>

// Description of task
// Write a C++ program to calculate x raised to the power n (xn). x=5, n=4. Use your own function.

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

double powerOf(int x, int n) {
    return pow(x, n);
}

int main() {
    do {
        std::cout << "Enter num\n";
        int x{readInt()};
        std::cout << "Enter to power of\n";
        int n{readInt()};

        std::cout << x << "^" << n << " is " << powerOf(x, n) << "\n";
    } while (tryAgain());

    return 0;
}
