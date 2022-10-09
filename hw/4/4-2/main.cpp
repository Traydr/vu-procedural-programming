#include <iostream>

// Description of task
// Write a program in C++ to display the cube of the number up to chosen integer. (n=5; 1,8,27,64,125)

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

int main() {
    do {
        std::cout << "Enter a number\n";
        int input = readInt();

        if (input < 0) {
            std::cout << "Enter a number bigger than 0\n";
            continue;
        }

        for (int i = 1; i <= input; i++) {
            int cube{i*i*i};
            std::cout << "Cube of " << i << " is " << cube << "\n";
        }

    } while (tryAgain());

    return 0;
}
