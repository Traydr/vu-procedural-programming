#include <iostream>

// Description of task
// Write a C++ program to accept a coordinate point in a XY coordinate system and
// determine in which quadrant the coordinate point lies

/* QUADRANTS
 * 2 | 1
 * -----
 * 3 | 4
 */

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
            std::cout << "Invalid input; please re-enter.\n";
        }
    } while (!valid);

    return input;
}

int main() {
    int x{0};
    int y{0};

    do {
        std::cout << "Enter x value\n";
        x = read_int();
        std::cout << "Enter y value\n";
        y = read_int();

        int output{0};

        if (x >= 0 && y >= 0) output = 1;
        else if (x < 0 && y >= 0) output = 2;
        else if (x < 0 && y < 0) output = 3;
        else if (x >= 0 && y < 0) output = 4;

        std::cout << "Quadrant of points ( " << x << " , " << y << " ) is: " << output << "\n";

        x = 0;
        y = 0;
    } while (tryAgain());

    return 0;
}