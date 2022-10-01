#include <iostream>

// Description of task
// Write a C++ program that checks whether the sum of the angles entered makes a triangle

bool tryAgain() {
    char answer;
    std::cout << "Would you like to try again? (y)\n";
    std::cin >> answer;
    return answer == 'y';
}

float read_float() {
    float input{0};
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
    float input{0};
    float sum{0};

    do {
        for (int i  = 0; i < 3; i++) {
            std::cout << "Enter Angle " << i + 1 << ":\n";
            input = read_float();
            sum += input;
        }

        if (sum == 180) {
            std::cout << "Angles add up! This is a triangle\n";
        } else {
            std::cout << "Angles don't add up! This is NOT a triangle\n";
        }

        sum = 0;
        input = 0;
    } while (tryAgain());

    return 0;
}