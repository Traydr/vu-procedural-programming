#include <iostream>

// Description of task
// Write a program that sums only positive numbers from all entered numbers. Display the sum. If you entered the negative number the program stops.

bool tryAgain() {
    char answer;
    std::cout << "Would you like to try again? (y)\n";
    std::cin >> answer;
    return answer == 'y';
}

float readFloat() {
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
    do {
        float sum{0};
        float input;
        bool posIn{true};

        std::cout << "Enter numbers one-by-one pressing space everytime. When you want to end it enter a negative number\n";

        while (posIn) {
            input = readFloat();

            if (input < 0) {
                posIn = false;
                continue;
            }

            sum += input;
        }

        std::cout << "Sum of inputs was " << sum << "\n";
    } while (tryAgain());

    return 0;
}
